#!/bin/bash

cmake --build build/tests --target test_di -j
cd build && ctest --output-on-failure && cd ..
