#include <emscripten.h>

// #include "spz/src/cc/splat-types.h"
#include "spz/src/cc/splat-types.cc"
// #include "spz/src/cc/load-spz.h"
// #include "spz/src/cc/load-spz.cc"

#include <zlib.h>

using namespace std;
// using namespace spz;

extern "C"
{
  // EMSCRIPTEN_KEEPALIVE
  // int fib(int n)
  // {
  //   if (n <= 0)
  //   {
  //     return 0;
  //   }
  //   int i, t, a = 0, b = 1;
  //   for (i = 1; i < n; i++)
  //   {
  //     t = a + b;
  //     a = b;
  //     b = t;
  //   }
  //   return b;
  // }

  EMSCRIPTEN_KEEPALIVE
  float hoge()
  {
    // spz::GaussianCloud gs = {
    //     43, 0, false, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {1.0, 0.0, 0.0, 0.0}, {1.0}, {1.0, 1.0, 1.0}, {0.0}};

    spz::Vec3f v = {1, 2, 3};
    spz::Vec3f normalized = spz::normalized(v);
    return normalized[1];
    // return 1;
    //   return gs.data().shDegree;
    // return gs.numPoints;
  }
}