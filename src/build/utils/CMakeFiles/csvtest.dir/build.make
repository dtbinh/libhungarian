# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/rann/math/hungarian/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rann/math/hungarian/src/build

# Include any dependencies generated for this target.
include utils/CMakeFiles/csvtest.dir/depend.make

# Include the progress variables for this target.
include utils/CMakeFiles/csvtest.dir/progress.make

# Include the compile flags for this target's objects.
include utils/CMakeFiles/csvtest.dir/flags.make

utils/CMakeFiles/csvtest.dir/test.c.o: utils/CMakeFiles/csvtest.dir/flags.make
utils/CMakeFiles/csvtest.dir/test.c.o: ../utils/test.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/rann/math/hungarian/src/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object utils/CMakeFiles/csvtest.dir/test.c.o"
	cd /home/rann/math/hungarian/src/build/utils && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/csvtest.dir/test.c.o   -c /home/rann/math/hungarian/src/utils/test.c

utils/CMakeFiles/csvtest.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/csvtest.dir/test.c.i"
	cd /home/rann/math/hungarian/src/build/utils && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/rann/math/hungarian/src/utils/test.c > CMakeFiles/csvtest.dir/test.c.i

utils/CMakeFiles/csvtest.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/csvtest.dir/test.c.s"
	cd /home/rann/math/hungarian/src/build/utils && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/rann/math/hungarian/src/utils/test.c -o CMakeFiles/csvtest.dir/test.c.s

utils/CMakeFiles/csvtest.dir/test.c.o.requires:
.PHONY : utils/CMakeFiles/csvtest.dir/test.c.o.requires

utils/CMakeFiles/csvtest.dir/test.c.o.provides: utils/CMakeFiles/csvtest.dir/test.c.o.requires
	$(MAKE) -f utils/CMakeFiles/csvtest.dir/build.make utils/CMakeFiles/csvtest.dir/test.c.o.provides.build
.PHONY : utils/CMakeFiles/csvtest.dir/test.c.o.provides

utils/CMakeFiles/csvtest.dir/test.c.o.provides.build: utils/CMakeFiles/csvtest.dir/test.c.o

# Object files for target csvtest
csvtest_OBJECTS = \
"CMakeFiles/csvtest.dir/test.c.o"

# External object files for target csvtest
csvtest_EXTERNAL_OBJECTS =

utils/csvtest: utils/CMakeFiles/csvtest.dir/test.c.o
utils/csvtest: utils/CMakeFiles/csvtest.dir/build.make
utils/csvtest: utils/libreadcsv.a
utils/csvtest: utils/CMakeFiles/csvtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable csvtest"
	cd /home/rann/math/hungarian/src/build/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/csvtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
utils/CMakeFiles/csvtest.dir/build: utils/csvtest
.PHONY : utils/CMakeFiles/csvtest.dir/build

utils/CMakeFiles/csvtest.dir/requires: utils/CMakeFiles/csvtest.dir/test.c.o.requires
.PHONY : utils/CMakeFiles/csvtest.dir/requires

utils/CMakeFiles/csvtest.dir/clean:
	cd /home/rann/math/hungarian/src/build/utils && $(CMAKE_COMMAND) -P CMakeFiles/csvtest.dir/cmake_clean.cmake
.PHONY : utils/CMakeFiles/csvtest.dir/clean

utils/CMakeFiles/csvtest.dir/depend:
	cd /home/rann/math/hungarian/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rann/math/hungarian/src /home/rann/math/hungarian/src/utils /home/rann/math/hungarian/src/build /home/rann/math/hungarian/src/build/utils /home/rann/math/hungarian/src/build/utils/CMakeFiles/csvtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : utils/CMakeFiles/csvtest.dir/depend
