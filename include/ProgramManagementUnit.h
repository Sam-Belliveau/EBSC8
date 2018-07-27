#ifndef PROGRAMMANAGMENTUNIT_H
#define PROGRAMMANAGMENTUNIT_H

/*** Libraries ***/
#include <vector>

/*** Definitions ***/
#include "InstructionSet.h"
#include "TypeNames.h"

template<std::size_t program_space>
class ProgramManagementUnit
{
public: // Methods
  ProgramManagementUnit()
  {
    for(BYTE i : markers)
    { i = 0; }

    for(BYTE i : program)
    { i = 0; }
  }

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
    else { return OP_STOP; }
  }

  WORD getWord()
  {
    return (static_cast<WORD>(getByte()) << 8) +
            static_cast<WORD>(getByte());
  }

  void setMarker(const BYTE id)
  { markers[id] = program_counter; }

  void goToMarker(const BYTE id)
  { program_counter = markers[id]; }

public: // Variables
  WORD program_counter = 0;

private: // Variables
  WORD program_size = 0;
  WORD markers[0x100];
  BYTE program[program_space];
};

#endif
