#include "processor.h"


void Processor::INC(Address addr) // Increment a memory location N,Z
{
    Word result = mem->read(addr) + 1;
    mem->write(addr, result);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);
}

void Processor::INX() // Increment the X register  N,Z
{
    Word result = X.read() + 1;
    X.write(result);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);
}

void Processor::INY() // Increment the Y register  N,Z
{
    Word result = Y.read() + 1;
    Y.write(result);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);
}

void Processor::DEC(Address addr) // Decrement a memory location N,Z
{
    Word result = mem->read(addr) - 1;
    mem->write(addr, result);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);
}

void Processor::DEX() // Decrement the X register  N,Z
{
    Word result = X.read() - 1;
    X.write(result);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);
}

void Processor::DEY() // Decrement the Y register  N,Z
{
    Word result = Y.read() - 1;
    Y.write(result);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);
}
