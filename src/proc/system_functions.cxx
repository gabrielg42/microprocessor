#include <stdexcept>
#include "processor.h"

void Processor::NOP()
{
    return;
}

void Processor::ReturnFromInterrupt()
{
    throw std::logic_error("RTI not implemented");
}


void Processor::BRK()
{
    // The program counter and processor status are pushed on the stack then the IRQ interrupt vector at $FFFE/F is loaded into the PC and the break flag in the status set to one.
    processor_status_r.set_status(ProcessorStatus::BRK, true);
    throw std::logic_error("BRK not fully implemented");
}