# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dickr/algorithm/swap_two_nums

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dickr/algorithm/swap_two_nums/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/swap_two_nums.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/swap_two_nums.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/swap_two_nums.dir/flags.make

CMakeFiles/swap_two_nums.dir/main.cpp.o: CMakeFiles/swap_two_nums.dir/flags.make
CMakeFiles/swap_two_nums.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dickr/algorithm/swap_two_nums/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/swap_two_nums.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/swap_two_nums.dir/main.cpp.o -c /Users/dickr/algorithm/swap_two_nums/main.cpp

CMakeFiles/swap_two_nums.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/swap_two_nums.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dickr/algorithm/swap_two_nums/main.cpp > CMakeFiles/swap_two_nums.dir/main.cpp.i

CMakeFiles/swap_two_nums.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/swap_two_nums.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dickr/algorithm/swap_two_nums/main.cpp -o CMakeFiles/swap_two_nums.dir/main.cpp.s

# Object files for target swap_two_nums
swap_two_nums_OBJECTS = \
"CMakeFiles/swap_two_nums.dir/main.cpp.o"

# External object files for target swap_two_nums
swap_two_nums_EXTERNAL_OBJECTS =

swap_two_nums: CMakeFiles/swap_two_nums.dir/main.cpp.o
swap_two_nums: CMakeFiles/swap_two_nums.dir/build.make
swap_two_nums: CMakeFiles/swap_two_nums.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dickr/algorithm/swap_two_nums/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable swap_two_nums"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/swap_two_nums.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/swap_two_nums.dir/build: swap_two_nums

.PHONY : CMakeFiles/swap_two_nums.dir/build

CMakeFiles/swap_two_nums.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/swap_two_nums.dir/cmake_clean.cmake
.PHONY : CMakeFiles/swap_two_nums.dir/clean

CMakeFiles/swap_two_nums.dir/depend:
	cd /Users/dickr/algorithm/swap_two_nums/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dickr/algorithm/swap_two_nums /Users/dickr/algorithm/swap_two_nums /Users/dickr/algorithm/swap_two_nums/cmake-build-debug /Users/dickr/algorithm/swap_two_nums/cmake-build-debug /Users/dickr/algorithm/swap_two_nums/cmake-build-debug/CMakeFiles/swap_two_nums.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/swap_two_nums.dir/depend
