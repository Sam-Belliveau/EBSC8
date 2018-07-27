#ifndef INSTRUCTIONSET_H
#define INSTRUCTIONSET_H

#define OP_STOP 0x00 // Stops The Computers

/*** Program Counter Manipulation ***/
#define OP_STMK 0x01 // Set Marker
#define OP_GTMK 0x02 // Go To Marker
#define OP_IFMK 0x03 // If Flag Is Set, Go To Marker

#define OP_STPC 0x04 // Set The Program Counter
#define OP_IFPC 0x05 // Set The Program Counter If The Flag Is Set

/*** Extentions ***/
#define OP_PURG 0xf0 // Print Unsigned Integer From Register
#define OP_PSRG 0xf1 // Print Signed Integer From Register
#define OP_PCRG 0xf2 // Print Char From Register

#define OP_PURM 0xf3 // Print Unsigned Integer From Ram
#define OP_PSRM 0xf4 // Print Signed Integer From Ram
#define OP_PCRM 0xf5 // Print Char From Ram

#endif
