#ifndef PROGRAMMANAGMENTUNIT_H
#define PROGRAMMANAGMENTUNIT_H

#include <vector>
#include "InstructionSet.h"
#include "TypeNames.h"

template<std::size_t program_space>
class ProgramManagementUnit
{
public:
  void loadProgram(const std::vector<BYTE>& input_program)
  {
    program_size = input_program.size();
    program_counter = 0;

    std::size_t byte_pointer = 0;
    for(BYTE i : input_program)
    {
      program[byte_pointer] = i;
      byte_pointer++;
    }
  }

  BYTE getByte()
  {
    if(program_size > program_counter)
    { return program[program_counter++]; }

    return OP_STOP;
  }

  void setMarker(const BYTE id)
  { markers[id] = program_counter; }


  void goToMarker(const BYTE id)
  { program_counter = markers[id]; }

  WORD program_counter = 0;

private:
  WORD program_size = 0;
  WORD markers[0x100];
  BYTE program[program_space];
};

#endif
