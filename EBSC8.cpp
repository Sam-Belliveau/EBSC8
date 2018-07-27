#include "include/EBSC8.h"

void EBSC::runNextOPCODE()
{
  const BYTE OPCODE = PMU.getByte();

  if (OPCODE == OP_STOP)
  {
      running = false;
  }
  else if (OPCODE == OP_STMK)
  {
    PMU.setMarker(PMU.getByte());
  }
  else if (OPCODE == OP_GTMK)
  {
    PMU.goToMarker(PMU.getByte());
  }
  else if (OPCODE == OP_IFMK)
  {
    if(MMU.flag)
    { PMU.goToMarker(PMU.getByte()); }
    else { PMU.getByte(); }
  }
  else if (OPCODE == OP_STPC)
  {
    PMU.program_counter = PMU.getByte();
  }
  else if (OPCODE == OP_IFPC)
  {
    if(MMU.flag)
    { PMU.program_counter = PMU.getByte(); }
    else { PMU.getByte(); }
  }
}
