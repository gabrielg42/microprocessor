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


      test_word = 0x11;
      proc.accumulator.write(test_word);
      proc.TAX();
      assert(proc.X.read()==test_word);

      test_word = 0x14;
      proc.accumulator.write(test_word);
      proc.TAY();
      assert(proc.Y.read()==test_word);

      test_word = 0x15;
      proc.X.write(test_word);
      proc.TXA();
      assert(proc.accumulator.read()==test_word);

      test_word = 0x16;
      proc.Y.write(test_word);
      proc.TYA();
      assert(proc.accumulator.read()==test_word);
    }
};

int main()
{
    ProcessorTester::test_processor();
}