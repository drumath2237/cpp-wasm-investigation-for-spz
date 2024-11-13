#include <emscripten.h>

#include "spz/src/cc/splat-types.h"
#include "spz/src/cc/splat-types.cc"

#include "spz/src/cc/load-spz.h"
#include "spz/src/cc/load-spz.cc"

using namespace std;
// using namespace spz;

extern "C"
{
  EMSCRIPTEN_KEEPALIVE
  float hoge()
  {
    spz::GaussianCloud gs = {
        1, 0, false, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {1.0, 0.0, 0.0, 0.0}, {1.0}, {1.0, 1.0, 1.0}, {}};

    vector<uint8_t> binGS;

    spz::saveSpz(gs, &binGS);

    spz::PackedGaussians unpackedGS = spz::loadSpzPacked(binGS);

    return unpackedGS.numPoints;
  }
}