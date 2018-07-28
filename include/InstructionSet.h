#ifndef INSTRUCTIONSET_H
#define INSTRUCTIONSET_H

#define OP_STOP 0x00 // Stops The Computers

/*** Program Counter Manipulation ***/
#define OP_STMK 0x01 // Set Marker
#define OP_GTMK 0x02 // Go To Marker
#define OP_IFMK 0x03 // If Flag Is Set, Go To Marker

#define OP_STPC 0x04 // Set The Program Counter
#define OP_IFPC 0x05 // Set The Program Counter If The Flag Is Set

/*** Register Initalization ***/
#define OP_SARM 0x10 // Set Register (a) To Ram Address
#define OP_SBRM 0x11 // Set Register (b) To Ram Address
#define OP_SCRM 0x12 // Set Register (c) To Ram Address
#define OP_SDRM 0x13 // Set Register (d) To Ram Address
#define OP_SERM 0x14 // Set Register (e) To Ram Address
#define OP_SFRM 0x15 // Set Register (f) To Ram Address

#define OP_SAPA 0x16 // Set Register (a) To The Pointers Ram Address
#define OP_SBPA 0x17 // Set Register (b) To The Pointers Ram Address
#define OP_SCPA 0x18 // Set Register (c) To The Pointers Ram Address
#define OP_SDPA 0x19 // Set Register (d) To The Pointers Ram Address
#define OP_SEPA 0x1A // Set Register (e) To The Pointers Ram Address
#define OP_SFPA 0x1B // Set Register (f) To The Pointers Ram Address

#define OP_STPT 0x1C // Set Pointer
#define OP_INPT 0x1D // Increment Pointer
#define OP_ADPT 0x1E // Add to Pointer
#define OP_SBPT 0x1F // Sub From Pointer

/*** Feeding Registers Into Ram ***/
#define OP_SRMA 0x20 // Set Ram Address To Register (a)
#define OP_SRMB 0x21 // Set Ram Address To Register (b)
#define OP_SRMC 0x22 // Set Ram Address To Register (c)
#define OP_SRMD 0x23 // Set Ram Address To Register (d)
#define OP_SRME 0x24 // Set Ram Address To Register (e)
#define OP_SRMF 0x25 // Set Ram Address To Register (f)

#define OP_SPAA 0x26 // Set The Pointers Ram Address To Register (a)
#define OP_SPAB 0x27 // Set The Pointers Ram Address To Register (b)
#define OP_SPAC 0x28 // Set The Pointers Ram Address To Register (c)
#define OP_SPAD 0x29 // Set The Pointers Ram Address To Register (d)
#define OP_SPAE 0x2A // Set The Pointers Ram Address To Register (e)
#define OP_SPAF 0x2B // Set The Pointers Ram Address To Register (f)

#define OP_STRM 0x2C // Set Ram Address
#define OP_STPA 0x2D // Set Pointers Ram Address

/*** Comparison Operators ***/
#define OP_TONF 0x30 // Turn On Flag
#define OP_TOFF 0x31 // Turn Off Flag
#define OP_FLPF 0x32 // Flip Flag

#define OP_ALTB 0x33 // Turn On Flag If A Is Less Than B
#define OP_AGTB 0x34 // Turn On Flag If A Is Greater Than B
#define OP_ALEB 0x35 // Turn On Flag If A Is Less Than Or Equal To B
#define OP_AGEB 0x36 // Turn On Flag If A Is Greater Than Or Equal To B
#define OP_AEQB 0x37 // Turn On Flag If A Is Equal To B
#define OP_ANEB 0x38 // Turn On Flag If A Is Not Equal To B

/*** Math ***/
#define OP_CINC 0x40 // Increment Register C By One
#define OP_CDEC 0x41 // Decrement Register C By One

#define OP_CADI 0x42 // Add To Register C
#define OP_CADR 0x43 // Add Ram Address To Register C
#define OP_CADP 0x44 // Add Pointers Ram Address To Register C

#define OP_CSBI 0x45 // Sub From Register C
#define OP_CSBR 0x46 // Sub Ram Address From Register C
#define OP_CSBP 0x47 // Sub Pointers Ram Address From Register C

#define OP_CMLI 0x48 // Mul Register C
#define OP_CMLR 0x49 // Mul Ram Address To Register C
#define OP_CMLP 0x4A // Mul Pointers Ram Address To Register C

#define OP_CDII 0x4B // Divide Register C
#define OP_CDIR 0x4C // Divide Register C By Ram Address
#define OP_CDIP 0x4D // Divide Register C By Pointers Ram Address

#define OP_CMDI 0x4E // Modulo Register C
#define OP_CMDR 0x4F // Modulo Register C By Ram Address
#define OP_CMDP 0x50 // Modulo Register C By Pointers Ram Address

#define OP_CXRI 0x51 // Register C Xor
#define OP_CXRR 0x52 // Register C Xor Ram Address
#define OP_CXRP 0x53 // Register C Xor Pointers Ram Address

#define OP_CORI 0x54 // Register C or
#define OP_CORR 0x55 // Register C or Ram Address
#define OP_CORP 0x56 // Register C or Pointers Ram Address

#define OP_CANI 0x57 // Register C and
#define OP_CANR 0x58 // Register C and Ram Address
#define OP_CANP 0x59 // Register C and Pointers Ram Address

#define OP_CSLI 0x5A // Shift Register C Left By
#define OP_CSLR 0x5B // Shift Register C Left By Ram Address
#define OP_CSLP 0x5C // Shift Register C Left By Pointers Ram Address

#define OP_CSRI 0x5D // Shift Register C Right By
#define OP_CSRR 0x5E // Shift Register C Right By Ram Address
#define OP_CSRP 0x5F // Shift Register C Right By Pointers Ram Address

/*** Extentions ***/
#define OP_PUPA 0xF0 // Print Unsigned Integer From Pointers Ram Address
#define OP_PSPA 0xF1 // Print Signed Integer From Pointers Ram Address
#define OP_PCPA 0xF2 // Print Char From Pointers Ram Address

#define OP_PURM 0xF3 // Print Unsigned Integer From Ram Address
#define OP_PSRM 0xF4 // Print Signed Integer From Ram Address
#define OP_PCRM 0xF5 // Print Char From Ram Address

#define OP_PUPR 0xF6 // Print Unsigned Int From Program
#define OP_PSPR 0xF7 // Print Signed Int From Program
#define OP_PCPR 0xF8 // Print Char From From Program
#define OP_PNTS 0xF9 // Print Null Terminated String

#define OP_INCD 0xFA // Get Character As Input, and Store It In Register D
#define OP_INUD 0xFA // Get Unsigned Int As Input, and Store It In Register D

#endif
