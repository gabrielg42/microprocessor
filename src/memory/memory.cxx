#include "memory.h"

Word Memory::read(Address addr)
{
    return memory[addr];
}
void Memory::write(Address addr, Word word)
{
    memory[addr] = word;
    return;
}