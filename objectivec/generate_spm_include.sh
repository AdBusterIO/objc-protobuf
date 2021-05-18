#!/bin/bash

set -eu

rm -r include || true
mkdir include
mkdir include/Protobuf

ln -s ../google include/google
find . -maxdepth 1 -type f -name "*.h" -exec sh -c 'echo "ln -s $(realpath --relative-to=include {}) include/$(basename -- {})"; ln -s $(realpath --relative-to=include {}) include/$(basename -- {})' \;
#find "google/protobuf" -maxdepth 1 -type f -name "*.h" -exec sh -c 'echo "ln -s $(realpath --relative-to=include/Protobuf {}) include/Protobuf/$(basename -- {})"; ln -s $(realpath --relative-to=include/Protobuf {}) include/Protobuf/$(basename -- {})' \;
