#include "processor.h"

void Processor::ADC(Word operand)
{
    uint16_t result16 = static_cast<uint16_t>(accumulator.read()) 
        + static_cast<uint16_t>(operand)
        + static_cast<uint16_t>(get_carry_bit());
    Word result = static_cast<Word>(result16 & 0xFF);
    accumulator.write(result);
    set_carry_flag_if(result16 > 0xFF);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);
    // The overflow flag is set during arithmetic operations 
    // if the result has yielded an invalid 2's complement result 
    // (e.g. adding to positive numbers and ending up with a negative result: 64 + 64 => -128). 
    // It is determined by looking at the carry between bits 6 and 7 and between bit 7 and the carry flag.
    // set_overflow_flag_if_6th_bit();
}

void Processor::SBC(Word operand)
{
    Word not_carry_bit = 1-get_carry_bit();

    // documentation says to clear carry flag if overflow in bit 7
    // but what does that even mean? just if it changes sign?
    set_carry_flag_if((operand + not_carry_bit)>accumulator.read());
    Word result = accumulator.read() - operand - not_carry_bit;
    set_negative_flag_if_7th_bit(result);
    set_zero_flag_if_equals_zero(result);
}

void Processor::CMP(Word operand)
{
    Word result = accumulator.read() - operand;
    set_carry_flag_if(result >= 0);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);
}

void Processor::CPX(Word operand)
{
    Word result = X.read() - operand;
    set_carry_flag_if(result >= 0);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);
}

void Processor::CPY(Word operand)
{
    Word result = Y.read() - operand;
    set_carry_flag_if(result >= 0);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);
}