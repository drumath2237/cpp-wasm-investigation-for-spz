#!/bin/bash

em++ main.cpp \
 --std=c++17 -o \
 ./build/main.js \
 -s USE_ZLIB=1 \
 -v