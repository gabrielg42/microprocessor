#include <cassert>

#include "processor.h"
#include "register.h"

class ProcessorTester
{
public:
    void static test_processor()
    {
        Memory mem;
        Processor proc(&mem);
        Word test_operand, register_value;

        register_value = 0x1;
        test_operand = 0x2;
        proc.accumulator.write(register_value);
        proc.ADC(test_operand);
        assert(proc.accumulator.read() == (register_value+test_operand));
        assert(~proc.processor_status_r.get_status(ProcessorStatus::CARRY));
        assert(~proc.processor_status_r.get_status(ProcessorStatus::ZERO));
        assert(~proc.processor_status_r.get_status(ProcessorStatus::OVERFLOW));
        assert(~proc.processor_status_r.get_status(ProcessorStatus::NEGATIVE));


            
        register_value = 0xFF;
        test_operand = 0x1;
        proc.accumulator.write(register_value);
        proc.ADC(test_operand);
        assert(proc.accumulator.read() == (0));
        assert(proc.processor_status_r.get_status(ProcessorStatus::CARRY));
        assert(proc.processor_status_r.get_status(ProcessorStatus::ZERO));
        assert(proc.processor_status_r.get_status(ProcessorStatus::OVERFLOW));
        assert(~proc.processor_status_r.get_status(ProcessorStatus::NEGATIVE));
        // proc.SBC()
        // proc.CMP()
        // proc.CPX()
        // proc.CPY()
    }
};


int main()
{
    ProcessorTester::test_processor();
}