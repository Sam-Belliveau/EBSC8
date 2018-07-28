const std::vector<BYTE> program =
{
  OP_STRM, 0x00, 0x00, 0x01, // First Var
  OP_STRM, 0x00, 0x01, 0x01, // Secound Var
  OP_STRM, 0x00, 0x02, 0x7f, // Max Var
  OP_SBRM, 0x00, 0x02,

  OP_STMK, 0x00, // loop until number gets big

  OP_PCPR, '\n', // make new line
  OP_PIRM, 0x00, 0x00, // print first var
  OP_SCRM, 0x00, 0x00, // move first var to reg c
  OP_CADR, 0x00, 0x01, // add secound var
  OP_SRMC, 0x00, 0x00, // move back to first var

  OP_PCPR, '\n', // make new line
  OP_PIRM, 0x00, 0x01, // print secound var
  OP_SCRM, 0x00, 0x01, // move secound var into reg c
  OP_CADR, 0x00, 0x00, // add first var
  OP_SRMC, 0x00, 0x01, // move back to secound var

  OP_SARM, 0x00, 0x01, // load secound var into reg a
  OP_ALTB, // reg a is bigger than reg b (the max val)
  OP_IFMK, 0x00, // if its smaller, loop

  OP_STOP
};
