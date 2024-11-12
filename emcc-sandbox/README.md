# memo

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