#include "processor.h"

void Processor::set_zero_flag_if_equals_zero(Word word)
{
    processor_status_r.set_status(ProcessorStatus::ZERO, (word==0));
}

void Processor::set_negative_flag_if_7th_bit(Word word)
{
    processor_status_r.set_status(ProcessorStatus::NEGATIVE, (word & 1<<7)); 
}

void Processor::set_overflow_flag_if_6th_bit(Word word)
{
    processor_status_r.set_status(ProcessorStatus::OVERFLOW, (word & 1<<6)); 

}

void Processor::set_carry_flag_if(bool flag)
{
    processor_status_r.set_status(ProcessorStatus::CARRY, flag); 
}

bool Processor::get_carry_bit()
{
    return processor_status_r.get_status(ProcessorStatus::CARRY); 
}