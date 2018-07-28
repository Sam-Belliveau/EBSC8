#ifndef MEMORYMANAGEMENTUNIT_H
#define MEMORYMANAGEMENTUNIT_H

/*** Definitions ***/
#include "InstructionSet.h"
#include "TypeNames.h"

struct RegisterLayout
{
  /* Comparison Registers */
  bool flag = false;
  BYTE a = 0; BYTE b = 0;

  /* Math Registers */
  BYTE c = 0; BYTE d = 0;

  /* General Registers */
  BYTE e = 0; BYTE f = 0;

  /* Pointer Register */
  WORD pt = 0;
};

template<std::size_t memory_size>
class MemoryManagementUnit
{
public: // Methods
  MemoryManagementUnit()
  {
    for(BYTE i : ram)
    { i = 0x00; }
  }

  BYTE& getMemory(const WORD pointer)
  {
    if(pointer < memory_size)
    {
      return ram[pointer];
    } else
    {
      out_of_bounds = true;
      return ram[memory_size-1];
    }
  }

public: // Variables
  RegisterLayout reg;
  bool out_of_bounds = false;

private: // Variables
  BYTE ram[memory_size];
};

#endif
