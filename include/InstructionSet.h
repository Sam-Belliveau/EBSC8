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
#define OP_TONF 0x2E // Turn On Flag
#define OP_TOFF 0x2F // Turn Off Flag
#define OP_FLPF 0x30 // Flip Flag

#define OP_ALTB 0x31 // Turn On Flag If A Is Less Than B
#define OP_AGTB 0x32 // Turn On Flag If A Is Greater Than B
#define OP_ALEB 0x33 // Turn On Flag If A Is Less Than Or Equal To B
#define OP_AGEB 0x34 // Turn On Flag If A Is Greater Than Or Equal To B
#define OP_AEQB 0x35 // Turn On Flag If A Is Equal To B
#define OP_ANEB 0x36 // Turn On Flag If A Is Not Equal To B

/*** Extentions ***/
#define OP_PUPA 0xf0 // Print Unsigned Integer From Pointers Ram Address
#define OP_PSPA 0xf1 // Print Signed Integer From Pointers Ram Address
#define OP_PCPA 0xf2 // Print Char From Pointers Ram Address

#define OP_PURM 0xf3 // Print Unsigned Integer From Ram Address
#define OP_PSRM 0xf4 // Print Signed Integer From Ram Address
#define OP_PCRM 0xf5 // Print Char From Ram Address

#define OP_PUPR 0xf6 // Print Unsigned Integer From Program
#define OP_PSPR 0xf7 // Print Signed Integer From Program
#define OP_PCPR 0xf8 // Print Char From From Program
#define OP_PNTS 0xf9 // Print Null Terminated String


#endif
