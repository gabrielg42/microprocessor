#include "processor.h"

void Processor::ClearCarryFlag()
{
    processor_status_r.set_status(ProcessorStatus::CARRY, false);
}

void Processor::ClearDecimalModeFlag()
{
    processor_status_r.set_status(ProcessorStatus::DECIMAL, false);
}

void Processor::ClearInterruptDisableFlag()
{
    processor_status_r.set_status(ProcessorStatus::IRQB_DISABLE, false);
}

void Processor::ClearOverflowFlag()
{
    processor_status_r.set_status(ProcessorStatus::OVERFLOW, false);
}

void Processor::SetCarryFlag()
{
    processor_status_r.set_status(ProcessorStatus::CARRY, true);
}

void Processor::SetDecimalModeFlag()
{
    processor_status_r.set_status(ProcessorStatus::DECIMAL, true);
}

void Processor::SetInterruptDisableFlag()
{
    processor_status_r.set_status(ProcessorStatus::IRQB_DISABLE, true);
}
