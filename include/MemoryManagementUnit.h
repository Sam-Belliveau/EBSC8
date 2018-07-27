#ifndef MEMORYMANAGEMENTUNIT_H
#define MEMORYMANAGEMENTUNIT_H

/*** Definitions ***/
#include "InstructionSet.h"
#include "TypeNames.h"

template<std::size_t register_size, std::size_t memory_size>
class MemoryManagementUnit
{
public: // Methods
  MemoryManagementUnit()
  {
    for(BYTE i : ram)
    { i = 0x00; }

    for(BYTE i : registers)
    { i = 0x00; }

    flag = false;
  }

public: // Variables
  BYTE ram[memory_size];
  BYTE registers[register_size];
  bool flag = false; // used for compairisons
};

#endif
