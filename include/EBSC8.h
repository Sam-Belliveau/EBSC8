#ifndef EBSC8
#define EBSC8

/*** Extentions ***/
#include "Console.h"
// #include "Display.h" NOT FUNCTIONABLE

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

  void runNextOPCODE();

public: // Variables
  // Managers
  MemoryManagementUnit<0x100, 0x10000> MMU;
  ProgramManagementUnit<0x10000> PMU;

  // Extentions
  Console terminal;

  // Flags
  bool running = false;
};

#endif
