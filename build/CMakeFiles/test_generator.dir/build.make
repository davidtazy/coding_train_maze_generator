# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/CppProjects/canvas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/CppProjects/canvas/build

# Include any dependencies generated for this target.
include CMakeFiles/test_generator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_generator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_generator.dir/flags.make

CMakeFiles/test_generator.dir/test/test_generator.cpp.o: CMakeFiles/test_generator.dir/flags.make
CMakeFiles/test_generator.dir/test/test_generator.cpp.o: ../test/test_generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/CppProjects/canvas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_generator.dir/test/test_generator.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_generator.dir/test/test_generator.cpp.o -c /home/david/CppProjects/canvas/test/test_generator.cpp

CMakeFiles/test_generator.dir/test/test_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_generator.dir/test/test_generator.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/CppProjects/canvas/test/test_generator.cpp > CMakeFiles/test_generator.dir/test/test_generator.cpp.i

CMakeFiles/test_generator.dir/test/test_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_generator.dir/test/test_generator.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/CppProjects/canvas/test/test_generator.cpp -o CMakeFiles/test_generator.dir/test/test_generator.cpp.s

CMakeFiles/test_generator.dir/test/test_generator.cpp.o.requires:

.PHONY : CMakeFiles/test_generator.dir/test/test_generator.cpp.o.requires

CMakeFiles/test_generator.dir/test/test_generator.cpp.o.provides: CMakeFiles/test_generator.dir/test/test_generator.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_generator.dir/build.make CMakeFiles/test_generator.dir/test/test_generator.cpp.o.provides.build
.PHONY : CMakeFiles/test_generator.dir/test/test_generator.cpp.o.provides

CMakeFiles/test_generator.dir/test/test_generator.cpp.o.provides.build: CMakeFiles/test_generator.dir/test/test_generator.cpp.o


CMakeFiles/test_generator.dir/maze_generator.cpp.o: CMakeFiles/test_generator.dir/flags.make
CMakeFiles/test_generator.dir/maze_generator.cpp.o: ../maze_generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/CppProjects/canvas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_generator.dir/maze_generator.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_generator.dir/maze_generator.cpp.o -c /home/david/CppProjects/canvas/maze_generator.cpp

CMakeFiles/test_generator.dir/maze_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_generator.dir/maze_generator.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/CppProjects/canvas/maze_generator.cpp > CMakeFiles/test_generator.dir/maze_generator.cpp.i

CMakeFiles/test_generator.dir/maze_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_generator.dir/maze_generator.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/CppProjects/canvas/maze_generator.cpp -o CMakeFiles/test_generator.dir/maze_generator.cpp.s

CMakeFiles/test_generator.dir/maze_generator.cpp.o.requires:

.PHONY : CMakeFiles/test_generator.dir/maze_generator.cpp.o.requires

CMakeFiles/test_generator.dir/maze_generator.cpp.o.provides: CMakeFiles/test_generator.dir/maze_generator.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_generator.dir/build.make CMakeFiles/test_generator.dir/maze_generator.cpp.o.provides.build
.PHONY : CMakeFiles/test_generator.dir/maze_generator.cpp.o.provides

CMakeFiles/test_generator.dir/maze_generator.cpp.o.provides.build: CMakeFiles/test_generator.dir/maze_generator.cpp.o


CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o: CMakeFiles/test_generator.dir/flags.make
CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o: test_generator_automoc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/CppProjects/canvas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o -c /home/david/CppProjects/canvas/build/test_generator_automoc.cpp

CMakeFiles/test_generator.dir/test_generator_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_generator.dir/test_generator_automoc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/CppProjects/canvas/build/test_generator_automoc.cpp > CMakeFiles/test_generator.dir/test_generator_automoc.cpp.i

CMakeFiles/test_generator.dir/test_generator_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_generator.dir/test_generator_automoc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/CppProjects/canvas/build/test_generator_automoc.cpp -o CMakeFiles/test_generator.dir/test_generator_automoc.cpp.s

CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o.requires:

.PHONY : CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o.requires

CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o.provides: CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_generator.dir/build.make CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o.provides.build
.PHONY : CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o.provides

CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o.provides.build: CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o


# Object files for target test_generator
test_generator_OBJECTS = \
"CMakeFiles/test_generator.dir/test/test_generator.cpp.o" \
"CMakeFiles/test_generator.dir/maze_generator.cpp.o" \
"CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o"

# External object files for target test_generator
test_generator_EXTERNAL_OBJECTS =

test_generator: CMakeFiles/test_generator.dir/test/test_generator.cpp.o
test_generator: CMakeFiles/test_generator.dir/maze_generator.cpp.o
test_generator: CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o
test_generator: CMakeFiles/test_generator.dir/build.make
test_generator: /home/david/Qt5.9.8/5.9.8/gcc_64/lib/libQt5Test.so.5.9.8
test_generator: /home/david/Qt5.9.8/5.9.8/gcc_64/lib/libQt5Core.so.5.9.8
test_generator: CMakeFiles/test_generator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/CppProjects/canvas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_generator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_generator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_generator.dir/build: test_generator

.PHONY : CMakeFiles/test_generator.dir/build

CMakeFiles/test_generator.dir/requires: CMakeFiles/test_generator.dir/test/test_generator.cpp.o.requires
CMakeFiles/test_generator.dir/requires: CMakeFiles/test_generator.dir/maze_generator.cpp.o.requires
CMakeFiles/test_generator.dir/requires: CMakeFiles/test_generator.dir/test_generator_automoc.cpp.o.requires

.PHONY : CMakeFiles/test_generator.dir/requires

CMakeFiles/test_generator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_generator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_generator.dir/clean

CMakeFiles/test_generator.dir/depend:
	cd /home/david/CppProjects/canvas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/CppProjects/canvas /home/david/CppProjects/canvas /home/david/CppProjects/canvas/build /home/david/CppProjects/canvas/build /home/david/CppProjects/canvas/build/CMakeFiles/test_generator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_generator.dir/depend
