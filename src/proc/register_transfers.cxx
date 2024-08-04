#include "processor.h"

void Processor::TAX()
{
    Word word = accumulator.read();
    X.write(word);
    set_zero_flag_if_equals_zero(word);
    set_negative_flag_if_7th_bit(word);
}

void Processor::TAY()
{
    Word word = accumulator.read();
    Y.write(word);
    set_zero_flag_if_equals_zero(word);
    set_negative_flag_if_7th_bit(word);
}

void Processor::TXA()
{
    Word word = X.read();
    accumulator.write(word);
    set_zero_flag_if_equals_zero(word);
    set_negative_flag_if_7th_bit(word);
}

void Processor::TYA()
{
    Word word = Y.read();
    accumulator.write(word);
    set_zero_flag_if_equals_zero(word);
    set_negative_flag_if_7th_bit(word);
}
