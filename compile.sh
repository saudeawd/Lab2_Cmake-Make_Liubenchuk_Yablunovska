#!/bin/bash
set -e

LIB_NAME="myvector"
LIB_DIR="library"
EXAMPLES_DIR="examples"
BUILD_DIR="build"

mkdir -p $LIB_DIR/$BUILD_DIR
mkdir -p $EXAMPLES_DIR/$BUILD_DIR

g++ -std=c++17 -fPIC -c $LIB_DIR/*.cpp -o $LIB_DIR/$BUILD_DIR/$LIB_NAME.o
ar rcs $LIB_DIR/$BUILD_DIR/lib$LIB_NAME.a $LIB_DIR/$BUILD_DIR/$LIB_NAME.o
g++ -std=c++17 -shared -o $LIB_DIR/$BUILD_DIR/lib$LIB_NAME.so $LIB_DIR/$BUILD_DIR/$LIB_NAME.o

if [ -f "$LIB_DIR/$BUILD_DIR/lib$LIB_NAME.a" ] && [ -f "$LIB_DIR/$BUILD_DIR/lib$LIB_NAME.so" ]; then
    echo "Library build successful"
else
    echo "Library build failed"
    exit 1
fi

for f in $EXAMPLES_DIR/*.cpp; do
    OUT_NAME=$(basename "${f%.cpp}")
    g++ -std=c++17 "$f" -I $LIB_DIR -L $LIB_DIR/$BUILD_DIR -l$LIB_NAME -o $EXAMPLES_DIR/$BUILD_DIR/$OUT_NAME
done

echo "Examples build successful"
echo "Build completed successfully"
