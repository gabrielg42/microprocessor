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
      Word test_word;
      Address addr;

      addr = 0xEE7C;
      test_word = 0x81;
      mem.write(addr, test_word);
      proc.INC(addr);
      assert(mem.read(addr) == test_word+1);

      addr = 0xE7C;
      test_word = 0xA1;
      mem.write(addr, test_word);
      proc.DEC(addr);
      assert(mem.read(addr) == test_word-1);

      test_word = 0xAB;
      proc.X.write(test_word);
      proc.INX();
      assert(proc.X.read() == test_word+1);

      test_word = 0xFC;
      proc.Y.write(test_word);
      proc.INY();
      assert(proc.Y.read() == test_word+1);

      test_word = 0x45;
      proc.X.write(test_word);
      proc.DEX();
      assert(proc.X.read() == test_word-1);

      test_word = 0x54;
      proc.Y.write(test_word);
      proc.DEY();
      assert(proc.Y.read() == test_word-1);
    }
};

int main()
{
    ProcessorTester::test_processor();
}