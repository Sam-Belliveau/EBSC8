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

  /* Math Register */
  BYTE c = 0;

  /* Input Regester */
  BYTE d = 0;

  /* General Registers */
  BYTE e = 0;
  BYTE f = 0;

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

    reg.flag = false;
    reg.a = 0; reg.b = 0;
    reg.c = 0; reg.d = 0;
    reg.e = 0; reg.f = 0;
    reg.pt = 0;
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
