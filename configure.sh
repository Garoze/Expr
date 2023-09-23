#!/bin/sh

CHECK_FOLDERS='build, bin'

for folder in $(echo "$CHECK_FOLDERS" | sed "s/,/ /g"); do
  if [ ! -d "$folder" ]; then
    echo "Creating $folder..."
    mkdir "$folder"
  fi
done

cmake -S . -B build -GNinja -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON
cmake --build build
GTEST_COLOR=1 ctest --test-dir build --output-on-failure -j4
