#include <cassert>

#include "register.h"
#include "memory.h"

int main()
{
    ProcessorStatusRegister psr;

    // Assert all bits zero on creation
    assert(psr.get_status(ProcessorStatus::CARRY)==0);
    assert(psr.get_status(ProcessorStatus::ZERO)==0);
    assert(psr.get_status(ProcessorStatus::IRQB_DISABLE)==0);
    assert(psr.get_status(ProcessorStatus::DECIMAL)==0);
    assert(psr.get_status(ProcessorStatus::BRK)==0);
    assert(psr.get_status(ProcessorStatus::ONE)==0);
    assert(psr.get_status(ProcessorStatus::OVERFLOW)==0);
    assert(psr.get_status(ProcessorStatus::NEGATIVE)==0);

    // Assert we cannot write to the register arbitrarily
    bool exception_raised = false;
    try{
        psr.write(100);
    } catch (...) {
        exception_raised = true;
    }
    assert(exception_raised);

    // Assert that reading and writing individual flags works
    // The flag is set correctly and no other bits are affected
    // Testing with only one bit here because
    //   the underlying logic to toggle the bits is the same.
    psr.set_status(ProcessorStatus::CARRY, 0);
    assert(psr.read()==0);

    psr.set_status(ProcessorStatus::CARRY, 1);
    assert(psr.read()==1);

    psr.set_status(ProcessorStatus::CARRY, 0);
    assert(psr.read()==0);
}