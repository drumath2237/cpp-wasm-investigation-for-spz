#include "./spz/src/cc/load-spz.cc"

#include <cstdio>
#include <vector>

using namespace std;
using namespace spz;

int main(void){
  GaussianCloud gs = {
      1,
      1,
      false,
      {0, 0, 0},
      {1, 1, 1},
      {1, 0, 0, 0},
      {1},
      {1, 1, 1},
      {1}};

  // spz::saveSpz(gs, "test.spz");
  // spz::loadSpz("hello.spz");

  loadSplatFromPly("hello");

  // printf("%zu\n", gs.colors);

  return 0;
}