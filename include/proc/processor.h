#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "memory.h"
#include "register.h"

class Processor
{
  public:
    start();
  private:
    // Registers 
    Register<Word> ir;    
    Register<Word> accumulator;
    Register<Word> X;
    Register<Word> Y;
    ProcessorStatusRegister processor_status_r;
    Register<Word> stack_pointer_r;
    Register<Address> program_counter_r;

};

#endif // #ifndef PROCESSOR_H