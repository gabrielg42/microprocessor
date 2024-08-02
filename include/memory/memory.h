#ifndef MEMORY_H
#define MEMORY_H

#include "stdint.h"

typedef uint16_t Address;
typedef uint8_t Word;

class Memory {
  public:
    Word read(Address addr);
    void write(Address addr, Word word);
  private:
    Word memory[1 << 16];
};

#endif // #ifndef MEMORY_H