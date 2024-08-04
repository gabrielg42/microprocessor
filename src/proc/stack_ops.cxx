#include "processor.h"

void Processor::TSX()
{
    X.write(stack_pointer_r.read());
}

void Processor::TXS()
{
    stack_pointer_r.write(X.read());
}

void Processor::PHA()
{
    Address addr = 0x0100 & stack_pointer_r.read();
    mem->write(addr, accumulator.read());
    stack_pointer_r--;
}

void Processor::PHP()
{
    Address addr = 0x0100 & stack_pointer_r.read();
    mem->write(addr, processor_status_r.read());
    stack_pointer_r--;
}

void Processor::PLA()
{
    Address addr = 0x0100 & stack_pointer_r.read();
    mem->write(addr, accumulator.read());
    stack_pointer_r++;
}

void Processor::PLP()
{
    Address addr = 0x0100 & stack_pointer_r.read();
    mem->write(addr, processor_status_r.read());
    stack_pointer_r++;
}
