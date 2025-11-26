# Lab Work 2: Writing Make and CMake files for compiling a library and executable programs

Authors (work distribution):

* [Yablunovska Anastasiia](https://github.com/ystacy-ab) – Makefiles for library and examples, CMakeLists.txt for library and examples, root-level CMakeLists.txt
* [Liubenchuk Anastasiia](https://github.com/saudeawd) – Examples, Shell compilation scripts

## Prerequisites

* GCC/G++ compiler
* Make
* CMake (version 3.10 or higher)

## Project Structure

```
root/
- library/      # library code for int
- example/      # example programs using the library
- Makefile      # optional root Makefile
- CMakeLists.txt # root CMakeLists.txt
- compile.sh    # shell compilation script
```

## Compilation

### Using Bash Scripts

```bash
./compile.sh
```

* Builds **static** (`libmylib.a`) and **shared** (`libmylib.so`) versions of the library
* Compiles examples linking with the shared library

### Using Make

```bash
make
```

### Using CMake

```bash
mkdir -p build
cd build
cmake ..
make

```

## Installation

* All required files are included in the project structure
* No additional installation is needed


## Notes

* Library is built as **static** (`.a`) and **shared** (`.so`)
* Examples always link against the **shared library**
* Build artifacts are organized in `bin/` and `obj/` directories

## About

This lab demonstrates practical experience with multiple build systems (Bash scripts, Make, and CMake) for compiling a library and example programs in C/C++.
