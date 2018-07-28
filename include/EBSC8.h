#ifndef EBSC8
#define EBSC8

/*** Extentions ***/
#include "Console.h"

/*** Definitions ***/
#include "TypeNames.h"
#include "InstructionSet.h"

/*** Managers ***/
#include "MemoryManagementUnit.h"
#include "ProgramManagementUnit.h"

/*** CPU ***/
class EBSC
{
public: // Methods
  void startProgram()
  {
    running = true;
    while(running)
    {
      runNextOPCODE();
    }
  }

  void runNextOPCODE();

public: // Variables
  // Managers
  MemoryManagementUnit<0x8000> MMU;
  ProgramManagementUnit<0x10000> PMU;

  // Extentions
  Console terminal;

  // Flags
  bool running = false;
  bool unknown_opcode = false;
};

#endif
