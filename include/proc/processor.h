#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "memory.h"
#include "register.h"

class Processor
{
  public:
    void start();
    void reset();
    Processor(Memory* mem) : mem(mem) {
      reset();
    };
  private:
    Processor() = delete;

    // Registers 
    Register<Word> ir;    
    Register<Word> accumulator;
    Register<Word> X;
    Register<Word> Y;
    ProcessorStatusRegister processor_status_r;
    StackPointerRegister stack_pointer_r;
    Register<Address> program_counter_r;

    Memory* mem;
    bool reset_flag=false;

    //
    // Instruction set
    // Order from: http://www.6502.org/users/obelisk/6502/instructions.html
    //

    // Load/Store operations
    void LoadAccumulator(Address addr);
    void LoadXRegister(Address addr);
    void LoadYRegister(Address addr);
    void StoreAccumulator(Address addr);
    void StoreXRegister(Address addr);
    void StoreYRegister(Address addr);

    // Register transfers
    void TXA();
    void TYA();
    void TAX();
    void TAY();

    // Stack operations
    void TSX(); // Transfer stack pointer to X N,Z
    void TXS(); // Transfer X to stack pointer  
    void PHA(); // Push accumulator on stack  
    void PHP(); // Push processor status on stack   
    void PLA(); // Pull accumulator from stack N,Z
    void PLP(); // Pull processor status from stack  All

    // Logical
    void AND(Word operand);
    void EOR(Word operand); // Exclusive OR
    void ORA(Word operand); // Logical inclusive OR
    void BIT(Word operand);

    // Arithmetic
    void ADC(Word operand); // Add with Carry  N,V,Z,C
    void SBC(Word operand); // Subtract with Carry N,V,Z,C
    void CMP(Word operand); // Compare accumulator N,Z,C
    void CPX(Word operand); // Compare X register  N,Z,C
    void CPY(Word operand); // Compare Y register  N,Z,C

    // Increments and decrements
    void INC(Address addr); // Increment a memory location N,Z
    void INX(); // Increment the X register  N,Z
    void INY(); // Increment the Y register  N,Z
    void DEC(Address addr); // Decrement a memory location N,Z
    void DEX(); // Decrement the X register  N,Z
    void DEY(); // Decrement the Y register  N,Z

    // Shifts
    void ASLAccumulator(); // Arithmetic Shift Left N,Z,C
    void LSRAccumulator(); // Logical Shift Right N,Z,C
    void ROLAccumulator(); // Rotate Left N,Z,C
    void RORAccumulator(); // Rotate Right  N,Z,C

    void ASLMemory(Address addr); // Arithmetic Shift Left N,Z,C
    void LSRMemory(Address addr); // Logical Shift Right N,Z,C
    void ROLMemory(Address addr); // Rotate Left N,Z,C
    void RORMemory(Address addr); // Rotate Right  N,Z,C

    // Jumps and calls
    void JMPO(); // Jump to another location   
    void JSRO(); // Jump to a subroutine   
    void RTSO(); // Return from subroutine

    // Branches
    void BCC(); // Branch if carry flag clear   
    void BCS(); // Branch if carry flag set   
    void BEQ(); // Branch if zero flag set  
    void BMI(); // Branch if negative flag set  
    void BNE(); // Branch if zero flag clear  
    void BPL(); // Branch if negative flag clear  
    void BVC(); // Branch if overflow flag clear  
    void BVS(); // Branch if overflow flag set


    // Status flag changes
    void ClearCarryFlag();
    void ClearDecimalModeFlag();
    void ClearInterruptDisableFlag();
    void ClearOverflowFlag();
    void SetCarryFlag();
    void SetDecimalModeFlag();
    void SetInterruptDisableFlag();


    // System functions
    void BRK(); // Force an interrupt  B
    void NOP(); // No Operation   
    void ReturnFromInterrupt(); // Return from Interrupt All



    // Common functions
    bool get_carry_bit();
    void set_carry_flag_if(bool);
    void set_zero_flag_if_equals_zero(Word word);
    void set_negative_flag_if_7th_bit(Word word);
    void set_overflow_flag_if_6th_bit(Word word);


    friend class ProcessorTester;

};

#endif // #ifndef PROCESSOR_H