#include "register.h"

CARRY_MASK          = 1 << 0;
ZERO_MASK           = 1 << 1;
IRQB_DISABLE_MASK   = 1 << 2;
DECIMAL_MASK        = 1 << 3;
BRK_MASK            = 1 << 4;
ONE_MASK            = 1 << 5;
OVERFLOW_MASK       = 1 << 6;
NEGATIVE_MASK       = 1 << 7;

void ProcessorStatusRegister::set_bit(uint bit_position){
    value |= 1 << bit_position
}

void ProcessorStatusRegister::clear_bit(uint bit_position){
    value &= ~(1 << bit_position);
}

void ProcessorStatusRegister::set_carry_flag(bool flag)
{
    flag ? set_bit(0) : clear_bit(0);
}
void ProcessorStatusRegister::set_negative_flag(bool flag);
void ProcessorStatusRegister::set_overflow_flag(bool flag);
void ProcessorStatusRegister::set_zero_flag(bool flag);
void ProcessorStatusRegister::set_decimal_flag(bool flag);
void ProcessorStatusRegister::set_irqb_disable_flag(bool flag);
void ProcessorStatusRegister::set_user_flag(bool flag);

bool ProcessorStatusRegister::get_carry_flag();
bool ProcessorStatusRegister::get_negative_flag();
bool ProcessorStatusRegister::get_overflow_flag();
bool ProcessorStatusRegister::get_zero_flag();
bool ProcessorStatusRegister::get_decimal_flag();
bool ProcessorStatusRegister::get_irqb_disable_flag();
bool ProcessorStatusRegister::get_user_flag();



/*

0 | 0 = 0
0 | 1 = 1
1 | 0 = 1
1 | 1 = 1


!(0 | 0) = 1
!(0 | 1) = 0
!(1 | 0) = 0
!(1 | 1) = 0

0 & 0 = 0
0 & 1 = 0
1 & 0 = 0
1 & 1 = 1

0 & 0 = 0
0 & 1 = 0
1 & 0 = 0
1 & 1 = 0



*/