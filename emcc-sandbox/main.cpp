#include <emscripten.h>

#include "spz/src/cc/splat-types.h"
#include "spz/src/cc/splat-types.cc"

#include "spz/src/cc/load-spz.h"
#include "spz/src/cc/load-spz.cc"

#include <zlib.h>

using namespace std;
// using namespace spz;

extern "C"
{
  EMSCRIPTEN_KEEPALIVE
  float hoge()
  {
    spz::GaussianCloud gs = {
        43, 0, false, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {1.0, 0.0, 0.0, 0.0}, {1.0}, {1.0, 1.0, 1.0}, {0.0}};

    return gs.numPoints;

    spz::Vec3f v1 = {1, 2, 3};
    spz::Vec3f v2 = {2, 3, 4};

    spz::Vec3f res = spz::plus(v1, v2);
    return spz::norm(res);
    // return 1;
    //   return gs.data().shDegree;
    // return gs.numPoints;
  }
}

#include <iostream>
#include <cstdio>

int main()
{
  spz::GaussianCloud gs = {
    1, 0, false,
    {0.0, 0.0, 0.0},
    {1.0, 1.0, 1.0},
    {1.0, 0.0, 0.0, 0.0},
    {1.0},
    {1.0, 1.0, 1.0},
    {}
  };

  vector<uint8_t> bin;
  spz::saveSpz(gs, &bin);

  for(int i=0; i<bin.size(); i++)
  {
    printf("%d, ", bin[i]);
  }
  printf("\n");
  

  return 0;
}