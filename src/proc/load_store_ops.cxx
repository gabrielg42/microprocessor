#include "processor.h"
#include "register.h"
#include "memory.h"

void Processor::LoadAccumulator(Address addr)
{
    Word word = mem->read(addr);
    accumulator.write(word);
    set_zero_flag_if_equals_zero(word);
    set_negative_flag_if_7th_bit(word);
}

void Processor::LoadXRegister(Address addr)
{
    Word word = mem->read(addr);
    X.write(word);
    set_zero_flag_if_equals_zero(word);
    set_negative_flag_if_7th_bit(word); 
}

void Processor::LoadYRegister(Address addr)
{
    Word word = mem->read(addr);
    Y.write(word);
    set_zero_flag_if_equals_zero(word);
    set_negative_flag_if_7th_bit(word);
}

void Processor::StoreAccumulator(Address addr)
{
    mem->write(addr, accumulator.read());  
}

void Processor::StoreXRegister(Address addr)
{
    mem->write(addr, X.read());
}

void Processor::StoreYRegister(Address addr)
{
    mem->write(addr, Y.read());
}