# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rauli/project/plorth/parser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rauli/project/plorth/parser/build

# Include any dependencies generated for this target.
include test/CMakeFiles/test_word.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/test_word.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test_word.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test_word.dir/flags.make

test/CMakeFiles/test_word.dir/test_word.cpp.o: test/CMakeFiles/test_word.dir/flags.make
test/CMakeFiles/test_word.dir/test_word.cpp.o: ../test/test_word.cpp
test/CMakeFiles/test_word.dir/test_word.cpp.o: test/CMakeFiles/test_word.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rauli/project/plorth/parser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/test_word.dir/test_word.cpp.o"
	cd /home/rauli/project/plorth/parser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/test_word.dir/test_word.cpp.o -MF CMakeFiles/test_word.dir/test_word.cpp.o.d -o CMakeFiles/test_word.dir/test_word.cpp.o -c /home/rauli/project/plorth/parser/test/test_word.cpp

test/CMakeFiles/test_word.dir/test_word.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_word.dir/test_word.cpp.i"
	cd /home/rauli/project/plorth/parser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rauli/project/plorth/parser/test/test_word.cpp > CMakeFiles/test_word.dir/test_word.cpp.i

test/CMakeFiles/test_word.dir/test_word.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_word.dir/test_word.cpp.s"
	cd /home/rauli/project/plorth/parser/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rauli/project/plorth/parser/test/test_word.cpp -o CMakeFiles/test_word.dir/test_word.cpp.s

# Object files for target test_word
test_word_OBJECTS = \
"CMakeFiles/test_word.dir/test_word.cpp.o"

# External object files for target test_word
test_word_EXTERNAL_OBJECTS =

test/test_word: test/CMakeFiles/test_word.dir/test_word.cpp.o
test/test_word: test/CMakeFiles/test_word.dir/build.make
test/test_word: test/CMakeFiles/test_word.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rauli/project/plorth/parser/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_word"
	cd /home/rauli/project/plorth/parser/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_word.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test_word.dir/build: test/test_word
.PHONY : test/CMakeFiles/test_word.dir/build

test/CMakeFiles/test_word.dir/clean:
	cd /home/rauli/project/plorth/parser/build/test && $(CMAKE_COMMAND) -P CMakeFiles/test_word.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test_word.dir/clean

test/CMakeFiles/test_word.dir/depend:
	cd /home/rauli/project/plorth/parser/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rauli/project/plorth/parser /home/rauli/project/plorth/parser/test /home/rauli/project/plorth/parser/build /home/rauli/project/plorth/parser/build/test /home/rauli/project/plorth/parser/build/test/CMakeFiles/test_word.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test_word.dir/depend

