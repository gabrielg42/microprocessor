#include "processor.h"

void Processor::AND(Word operand)
{
    Word result = accumulator.read() & operand;
    accumulator.write(result);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);

}

void Processor::EOR(Word operand) // Exclusive OR
{
    Word result = accumulator.read() ^ operand;
    accumulator.write(result);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);
}

void Processor::ORA(Word operand) // Logical inclusive OR
{
    Word result = accumulator.read() | operand;
    accumulator.write(result);
    set_zero_flag_if_equals_zero(result);
    set_negative_flag_if_7th_bit(result);
}

void Processor::BIT(Word operand)
{
    Word mask_pattern = accumulator.read();
    Word and_result = mask_pattern & operand;
    set_zero_flag_if_equals_zero(and_result);
    set_negative_flag_if_7th_bit(operand);
    set_overflow_flag_if_6th_bit(operand);
}
