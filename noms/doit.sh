#!/bin/sh

set -e
set -x

rm -rf build stage
cmake -S . -B build -G Ninja -D CMAKE_BUILD_TYPE=Release -D COMPONENT_TARGETS_ENABLED=NO
cmake --build build --config Release #XXX -j4 -- -v
cmake --version
cmake --install build --config Release --prefix stage

rm -rf build
cmake -S test -B build -G Ninja -D CMAKE_BUILD_TYPE=Debug -D CMAKE_PREFIX_PATH=$PWD/stage -D TEST_INSTALLED_VERSION=1
cmake --build build --config Debug -j4 -- -v

cd build && ctest --build-config Debug
