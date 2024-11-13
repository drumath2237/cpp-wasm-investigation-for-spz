#!/bin/bash

if [ ! -d build ]; then
  mkdir build
fi

em++ main.cpp \
 --std=c++17 -o \
 ./build/main.js \
 -s USE_ZLIB=1 \