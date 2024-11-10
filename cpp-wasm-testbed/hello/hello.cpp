#include "hello.hpp"

// __attribute__((export_name("hello")))

extern "C"
{
  int hello()
  {
    return 42;
  }
}