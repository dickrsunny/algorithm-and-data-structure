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
CMAKE_SOURCE_DIR = /Users/dickr/algorithm-and-data-structure/elevator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dickr/algorithm-and-data-structure/elevator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/elevator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/elevator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/elevator.dir/flags.make

CMakeFiles/elevator.dir/main.cpp.o: CMakeFiles/elevator.dir/flags.make
CMakeFiles/elevator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dickr/algorithm-and-data-structure/elevator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/elevator.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/elevator.dir/main.cpp.o -c /Users/dickr/algorithm-and-data-structure/elevator/main.cpp

CMakeFiles/elevator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/elevator.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dickr/algorithm-and-data-structure/elevator/main.cpp > CMakeFiles/elevator.dir/main.cpp.i

CMakeFiles/elevator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/elevator.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dickr/algorithm-and-data-structure/elevator/main.cpp -o CMakeFiles/elevator.dir/main.cpp.s

# Object files for target elevator
elevator_OBJECTS = \
"CMakeFiles/elevator.dir/main.cpp.o"

# External object files for target elevator
elevator_EXTERNAL_OBJECTS =

elevator: CMakeFiles/elevator.dir/main.cpp.o
elevator: CMakeFiles/elevator.dir/build.make
elevator: CMakeFiles/elevator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dickr/algorithm-and-data-structure/elevator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable elevator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/elevator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/elevator.dir/build: elevator

.PHONY : CMakeFiles/elevator.dir/build

CMakeFiles/elevator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/elevator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/elevator.dir/clean

CMakeFiles/elevator.dir/depend:
	cd /Users/dickr/algorithm-and-data-structure/elevator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dickr/algorithm-and-data-structure/elevator /Users/dickr/algorithm-and-data-structure/elevator /Users/dickr/algorithm-and-data-structure/elevator/cmake-build-debug /Users/dickr/algorithm-and-data-structure/elevator/cmake-build-debug /Users/dickr/algorithm-and-data-structure/elevator/cmake-build-debug/CMakeFiles/elevator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/elevator.dir/depend

