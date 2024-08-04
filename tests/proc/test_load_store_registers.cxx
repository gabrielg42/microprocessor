#include <cassert>

#include "processor.h"
#include "memory.h"


class ProcessorTester
{
  public:
    void static test_processor() 
    {
      Memory mem;
      Processor proc(&mem);
      Word test_word, extracted_word;
      Address addr_to_store_to, addr_to_load_from;

      test_word = 0x11;
      addr_to_load_from = 0xFFFC;
      addr_to_store_to = 0xFFFF;

      mem.write(addr_to_load_from, test_word);
      proc.LoadXRegister(addr_to_load_from);
      proc.StoreXRegister(addr_to_store_to);
      extracted_word = mem.read(addr_to_store_to);
      assert(extracted_word == test_word);


      test_word = 0x12;
      addr_to_load_from = 0xF123;
      addr_to_store_to = 0x1245;

      mem.write(addr_to_load_from, test_word);
      proc.LoadYRegister(addr_to_load_from);
      proc.StoreYRegister(addr_to_store_to);
      extracted_word = mem.read(addr_to_store_to);
      assert(extracted_word == test_word);


      test_word = 0x24;
      addr_to_load_from = 0x123;
      addr_to_store_to = 0x145;

      mem.write(addr_to_load_from, test_word);
      proc.LoadAccumulator(addr_to_load_from);
      proc.StoreAccumulator(addr_to_store_to);
      extracted_word = mem.read(addr_to_store_to);
      assert(extracted_word == test_word);
    }
};

int main()
{
    ProcessorTester::test_processor();
}