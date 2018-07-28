#include "include/EBSC8.h"

void EBSC::runNextOPCODE()
{
  const BYTE OPCODE = PMU.getByte();

  if (OPCODE == OP_STOP)
  { running = false; }

  /*** Program Counter Manipulation ***/
  else if (OPCODE == OP_STMK)
  { PMU.setMarker(PMU.getByte()); }

  else if (OPCODE == OP_GTMK)
  { PMU.goToMarker(PMU.getByte()); }

  else if (OPCODE == OP_IFMK)
  {
    if(MMU.reg.flag)
    { PMU.goToMarker(PMU.getByte()); }
    else { PMU.getByte(); }
  }

  else if (OPCODE == OP_STPC)
  { PMU.program_counter = PMU.getByte(); }

  else if (OPCODE == OP_IFPC)
  {
    if(MMU.reg.flag)
    { PMU.program_counter = PMU.getByte(); }
    else { PMU.getByte(); }
  }

  /*** Register Initalization ***/
  else if (OPCODE == OP_SARM)
  { MMU.reg.a = MMU.getMemory(PMU.getWord()); }
  else if (OPCODE == OP_SBRM)
  { MMU.reg.b = MMU.getMemory(PMU.getWord()); }
  else if (OPCODE == OP_SCRM)
  { MMU.reg.c = MMU.getMemory(PMU.getWord()); }
  else if (OPCODE == OP_SDRM)
  { MMU.reg.d = MMU.getMemory(PMU.getWord()); }
  else if (OPCODE == OP_SERM)
  { MMU.reg.e = MMU.getMemory(PMU.getWord()); }
  else if (OPCODE == OP_SFRM)
  { MMU.reg.f = MMU.getMemory(PMU.getWord()); }

  else if (OPCODE == OP_SAPA)
  { MMU.reg.a = MMU.getMemory(MMU.reg.pt); }
  else if (OPCODE == OP_SBPA)
  { MMU.reg.b = MMU.getMemory(MMU.reg.pt); }
  else if (OPCODE == OP_SCPA)
  { MMU.reg.c = MMU.getMemory(MMU.reg.pt); }
  else if (OPCODE == OP_SDPA)
  { MMU.reg.d = MMU.getMemory(MMU.reg.pt); }
  else if (OPCODE == OP_SEPA)
  { MMU.reg.e = MMU.getMemory(MMU.reg.pt); }
  else if (OPCODE == OP_SFPA)
  { MMU.reg.f = MMU.getMemory(MMU.reg.pt); }

  else if (OPCODE == OP_STPT)
  { MMU.reg.pt = PMU.getWord(); }
  else if (OPCODE == OP_INPT)
  { MMU.reg.pt++; }
  else if (OPCODE == OP_ADPT)
  { MMU.reg.pt += PMU.getWord(); }
  else if (OPCODE == OP_SBPT)
  { MMU.reg.pt -= PMU.getWord(); }

  /*** Feeding Registers Into Ram ***/
  else if (OPCODE == OP_SRMA)
  { MMU.getMemory(PMU.getWord()) = MMU.reg.a; }
  else if (OPCODE == OP_SRMB)
  { MMU.getMemory(PMU.getWord()) = MMU.reg.b; }
  else if (OPCODE == OP_SRMC)
  { MMU.getMemory(PMU.getWord()) = MMU.reg.c; }
  else if (OPCODE == OP_SRMD)
  { MMU.getMemory(PMU.getWord()) = MMU.reg.d; }
  else if (OPCODE == OP_SRME)
  { MMU.getMemory(PMU.getWord()) = MMU.reg.e; }
  else if (OPCODE == OP_SRMF)
  { MMU.getMemory(PMU.getWord()) = MMU.reg.f; }

  else if (OPCODE == OP_SPAA)
  { MMU.getMemory(MMU.reg.pt) = MMU.reg.a; }
  else if (OPCODE == OP_SPAB)
  { MMU.getMemory(MMU.reg.pt) = MMU.reg.b; }
  else if (OPCODE == OP_SPAC)
  { MMU.getMemory(MMU.reg.pt) = MMU.reg.c; }
  else if (OPCODE == OP_SPAD)
  { MMU.getMemory(MMU.reg.pt) = MMU.reg.d; }
  else if (OPCODE == OP_SPAE)
  { MMU.getMemory(MMU.reg.pt) = MMU.reg.e; }
  else if (OPCODE == OP_SPAF)
  { MMU.getMemory(MMU.reg.pt) = MMU.reg.f; }

  else if (OPCODE == OP_STRM)
  { MMU.getMemory(PMU.getWord()) = PMU.getByte(); }
  else if (OPCODE == OP_STPA)
  { MMU.getMemory(MMU.reg.pt) = PMU.getByte(); }

  /*** Comparison Operators ***/
  else if (OPCODE == OP_TONF)
  { MMU.reg.flag = true; }
  else if (OPCODE == OP_TOFF)
  { MMU.reg.flag = false; }
  else if (OPCODE == OP_FLPF)
  { MMU.reg.flag = !MMU.reg.flag; }

  else if (OPCODE == OP_ALTB)
  { MMU.reg.flag = MMU.reg.a < MMU.reg.b; }
  else if (OPCODE == OP_AGTB)
  { MMU.reg.flag = MMU.reg.a > MMU.reg.b; }
  else if (OPCODE == OP_ALEB)
  { MMU.reg.flag = MMU.reg.a <= MMU.reg.b; }
  else if (OPCODE == OP_AGEB)
  { MMU.reg.flag = MMU.reg.a <= MMU.reg.b; }
  else if (OPCODE == OP_AEQB)
  { MMU.reg.flag = MMU.reg.a == MMU.reg.b; }
  else if (OPCODE == OP_ANEB)
  { MMU.reg.flag = MMU.reg.a != MMU.reg.b; }

  /*** Extentions ***/
  else if (OPCODE == OP_PUPA)
  { terminal.printUnsigned(MMU.getMemory(MMU.reg.pt)); }
  else if (OPCODE == OP_PSPA)
  { terminal.printSigned(MMU.getMemory(MMU.reg.pt)); }
  else if (OPCODE == OP_PCPA)
  { terminal.printChar(MMU.getMemory(MMU.reg.pt)); }

  else if (OPCODE == OP_PURM)
  { terminal.printUnsigned(MMU.getMemory(PMU.getWord())); }
  else if (OPCODE == OP_PSRM)
  { terminal.printSigned(MMU.getMemory(PMU.getWord())); }
  else if (OPCODE == OP_PCRM)
  { terminal.printChar(MMU.getMemory(PMU.getWord())); }

  else if (OPCODE == OP_PUPR)
  { terminal.printUnsigned(PMU.getWord()); }
  else if (OPCODE == OP_PSPR)
  { terminal.printSigned(PMU.getWord()); }
  else if (OPCODE == OP_PCPR)
  { terminal.printChar(PMU.getWord()); }
  else if (OPCODE == OP_PNTS)
  {
    BYTE temp_char = PMU.getByte();
    while(temp_char != 0x00)
    {
      terminal.printChar(temp_char);
      temp_char = PMU.getByte();
    }
  }

  /*** Unknown OPCODE ***/
  else{ unknown_opcode = true; }
}
