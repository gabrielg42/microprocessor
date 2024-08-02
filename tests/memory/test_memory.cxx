#include <cassert>

#include "memory.h"

int main(){
    Memory mem;

    mem.write(1, 1);
    assert(mem.read(1) == 1);
    assert(mem.read(1) == 1);

    Address addr = 0;
    addr--;
    mem.write(addr, 1 << 7);
    assert(mem.read(addr) == 1<<7);
}