#!/bin/bash

rm -rf build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug -j
cd build/template/
./template_app
