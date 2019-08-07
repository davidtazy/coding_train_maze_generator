# maze generator in C++

## application.h
mimic p5.js application with a canvas as an interface

## qtcanvas.h
implements a canvas with Qt5 widget lib 

# maze_generator.h/cpp
implements the maze generator ["Recursive backtracker"](https://en.wikipedia.org/wiki/Maze_generation_algorithm)
pure c++ ; zero dependancies

## maze_application.h/cpp 
all drawing primitives to show maze genration
depends on application.h

## main.cpp
instanciate concrete canvas (aka qtCanvas)
run maze_application


# how to build

## dependancies
Qt5
Cmake > 3.0
c++11 compiler

## build and run steps (tested on ubuntu 16.04)
```
cd /path/to/this/directory
mkdir build && cd build
cmake CMAKE_PREFIX_PATH=/path/to/qt/lib ..
cmake --build . --target all
ctest
./canvas
```
