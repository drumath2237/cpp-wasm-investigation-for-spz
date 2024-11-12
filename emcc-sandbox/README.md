# memo

## env

- Windows 10 Home
- Docker Tookbox
- Node.js 20.9.0

## usage

`run.bat` like below.

```bat
docker run^
 --rm^
 --privileged^
 -v /path/to/dir:/src^
 emscripten/emsdk^
 emcc main.cpp -o ./build/main.js -s USE_ZLIB=1
@REM  emcc -O3 -s WASM=1 -s EXPORTED_RUNTIME_METHODS='["cwrap"]' main.cpp
```

`main.cpp` is like below.

```cpp
#include <zlib.h>
#include <emscripten.h>

extern "C"
{

  EMSCRIPTEN_KEEPALIVE
  int fib(int n)
  {
    if (n <= 0)
    {
      return 0;
    }
    int i, t, a = 0, b = 1;
    for (i = 1; i < n; i++)
    {
      t = a + b;
      a = b;
      b = t;
    }
    return b;
  }
}
```

```sh
./run.bat
```

`index.mjs`

```js
import { readFile } from "node:fs/promises";

const main = async () => {
  const wasmBinary = await readFile("./build/main.wasm");

  const { instance } = await WebAssembly.instantiate(wasmBinary);
  const { fib } = instance.exports;

  console.log(fib(20)); // -> 6765
};

main();
```