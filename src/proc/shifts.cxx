#include "processor.h"

void Processor::ASLAccumulator() // Arithmetic Shift Left N,Z,C
{
    bool carry = accumulator.read() & (1 << 7);
    Word result = accumulator.read() << 1;
    accumulator.write(result);
    set_negative_flag_if_7th_bit(result);
    set_zero_flag_if_equals_zero(result);
    set_carry_flag_if(carry);
}

void Processor::ASLMemory(Address addr) // Arithmetic Shift Left N,Z,C
{
    bool carry = mem->read(addr) & (1 << 7);
    Word result = mem->read(addr) << 1;
    mem->write(addr, result);
    set_negative_flag_if_7th_bit(result);
    set_zero_flag_if_equals_zero(result);
    set_carry_flag_if(carry);
}

void Processor::LSRAccumulator() // Arithmetic Shift Left N,Z,C
{
    bool carry = accumulator.read() & 1;
    Word result = accumulator.read() >> 1;
    accumulator.write(result);
    set_negative_flag_if_7th_bit(result);
    set_zero_flag_if_equals_zero(result);
    set_carry_flag_if(carry);
}

void Processor::LSRMemory(Address addr) // Arithmetic Shift Left N,Z,C
{
    bool carry = mem->read(addr) & 1;
    Word result = mem->read(addr) >> 1;
    mem->write(addr, result);
    set_negative_flag_if_7th_bit(result);
    set_zero_flag_if_equals_zero(result);
    set_carry_flag_if(carry);
}

void Processor::RORAccumulator() // Rotate Right  N,Z,C
{
    bool new_carry_bit = accumulator.read() & 1;
    bool old_carry_bit = processor_status_r.get_status(ProcessorStatus::CARRY);
    Word result = accumulator.read() >> 1 & old_carry_bit << 7;
    accumulator.write(result);
    set_carry_flag_if(new_carry_bit); 
}


void Processor::ROLAccumulator() // Rotate Right  N,Z,C
{
    bool new_carry_bit = accumulator.read() & 1 << 7;
    bool old_carry_bit = processor_status_r.get_status(ProcessorStatus::CARRY);
    Word result = accumulator.read() << 1 & old_carry_bit;
    accumulator.write(result);
    set_carry_flag_if(new_carry_bit); 
}

void Processor::RORMemory(Address addr) // Rotate Right  N,Z,C
{
    bool new_carry_bit = mem->read(addr) & 1;
    bool old_carry_bit = processor_status_r.get_status(ProcessorStatus::CARRY);
    Word result = mem->read(addr) >> 1 & old_carry_bit << 7;
    mem->write(addr, result);
    set_carry_flag_if(new_carry_bit); 
}


void Processor::ROLMemory(Address addr) // Rotate Right  N,Z,C
{
    bool new_carry_bit = mem->read(addr) & 1 << 7;
    bool old_carry_bit = processor_status_r.get_status(ProcessorStatus::CARRY);
    Word result = mem->read(addr) << 1 & old_carry_bit;
    mem->write(addr, result);
    set_carry_flag_if(new_carry_bit); 
}