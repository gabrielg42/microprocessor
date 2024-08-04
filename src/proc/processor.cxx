#import "processor.h"
#import "memory.h"


// Processor::Processor(Memory* mem)
// {
//     self->mem = mem;
// }

void Processor::start()
{
    Address next_addr = 0;
    Address addr_low = static_cast<Address>(mem->read(0xFFFC));
    Address addr_high = static_cast<Address>(mem->read(0XFFFD) << 8);
    program_counter_r.write(addr_high & addr_low);
    reset_flag = false;
}

void Processor::reset()
{
    reset_flag=true;
    stack_pointer_r.write(0xFF);
}