#ifndef REGISTER_H
#define REGISTER_H

#include "stdint.h"
#include <exception>

#include "memory.h"

template <typename T> 
class Register
{
  public:
    virtual T read() { return value; }
    virtual void write(T word) { value = word; return; }
  protected:
    T value;
};

enum ProcessorStatus{
  CARRY          = 0,
  ZERO           = 1,
  IRQB_DISABLE   = 2,
  DECIMAL        = 3,
  BRK            = 4,
  ONE            = 5,
  OVERFLOW       = 6,
  NEGATIVE       = 7
};

class ProcessorStatusRegister : public Register<Word>
{
  public:
    ProcessorStatusRegister(){value = 0;}
    void set_status(ProcessorStatus status, bool flag)
    {
      flag ? set_bit(status) : clear_bit(status);
    }
    bool get_status(ProcessorStatus status)
    {
      return read_bit(status);
    }

    void write(Word) override {throw std::exception();}
    
  private:
    void set_bit(uint8_t bit_position){
      value |= 1 << bit_position;
    }

    void clear_bit(uint8_t bit_position){
      value &= ~(1 << bit_position);
    }

    bool read_bit(uint8_t bit_position){
      return value & 1 << bit_position;
    }
};

#endif // #ifndef REGISTER_H