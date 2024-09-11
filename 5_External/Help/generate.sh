#!/bin/bash
cp CMakeLists_private.txt CMakeLists.txt
cmake -S . -B build
cmake --build build --target install
cp CMakeLists.txt.orig CMakeLists.txt