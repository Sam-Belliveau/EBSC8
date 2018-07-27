#ifndef CONSOLE_H
#define CONSOLE_H

/*** Libraries ***/
#include <iostream>

/*** Definitions ***/
#include "TypeNames.h"

// The reason the console is an object is because
// The Classes EBSC8 Contains Are Like Devices
class Console
{
public: // Methods
  void printSigned(const BYTE &input)
  { std::cout << static_cast<signed>(input); }

  void printUnsigned(const BYTE &input)
  { std::cout << static_cast<unsigned>(input); }

  void printChar(const BYTE &input)
  { std::cout << static_cast<char>(input); }

  BYTE getNum()
  { signed out; std::cin >> out; return static_cast<BYTE>(out); }

  BYTE getChar()
  { char out; std::cin >> out; return static_cast<BYTE>(out); }
};

#endif
