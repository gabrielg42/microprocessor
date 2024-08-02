#include <cassert>

#include "register.h"
#include "memory.h"

int main()
{
    Register<Word> r;
    r.write(100);
    assert((r.read() == 100));
}