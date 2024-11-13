#include <emscripten.h>
#include <emscripten/bind.h>

#include "spz/src/cc/splat-types.h"
#include "spz/src/cc/splat-types.cc"

#include "spz/src/cc/load-spz.h"
#include "spz/src/cc/load-spz.cc"

using namespace std;
using namespace spz;

float hoge()
{
  GaussianCloud gs = {
      1, 0, false, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {1.0, 0.0, 0.0, 0.0}, {1.0}, {1.0, 1.0, 1.0}, {}};

  vector<uint8_t> binGS;
  saveSpz(gs, &binGS);

  PackedGaussians unpackedGS = loadSpzPacked(binGS);

  return unpackedGS.numPoints;
}

int create_test(int points)
{
  GaussianCloud gs = {points};
  return gs.numPoints;
}

EMSCRIPTEN_BINDINGS(my_module)
{
  emscripten::function("create_test", &create_test);
  emscripten::function("hoge", &hoge);
}