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
CMAKE_SOURCE_DIR = /Users/dickr/algorithm/wa_jue_ji

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dickr/algorithm/wa_jue_ji/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/wa_jue_ji.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wa_jue_ji.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wa_jue_ji.dir/flags.make

CMakeFiles/wa_jue_ji.dir/main.cpp.o: CMakeFiles/wa_jue_ji.dir/flags.make
CMakeFiles/wa_jue_ji.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dickr/algorithm/wa_jue_ji/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wa_jue_ji.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wa_jue_ji.dir/main.cpp.o -c /Users/dickr/algorithm/wa_jue_ji/main.cpp

CMakeFiles/wa_jue_ji.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wa_jue_ji.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dickr/algorithm/wa_jue_ji/main.cpp > CMakeFiles/wa_jue_ji.dir/main.cpp.i

CMakeFiles/wa_jue_ji.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wa_jue_ji.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dickr/algorithm/wa_jue_ji/main.cpp -o CMakeFiles/wa_jue_ji.dir/main.cpp.s

# Object files for target wa_jue_ji
wa_jue_ji_OBJECTS = \
"CMakeFiles/wa_jue_ji.dir/main.cpp.o"

# External object files for target wa_jue_ji
wa_jue_ji_EXTERNAL_OBJECTS =

wa_jue_ji: CMakeFiles/wa_jue_ji.dir/main.cpp.o
wa_jue_ji: CMakeFiles/wa_jue_ji.dir/build.make
wa_jue_ji: CMakeFiles/wa_jue_ji.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dickr/algorithm/wa_jue_ji/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable wa_jue_ji"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wa_jue_ji.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wa_jue_ji.dir/build: wa_jue_ji

.PHONY : CMakeFiles/wa_jue_ji.dir/build

CMakeFiles/wa_jue_ji.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wa_jue_ji.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wa_jue_ji.dir/clean

CMakeFiles/wa_jue_ji.dir/depend:
	cd /Users/dickr/algorithm/wa_jue_ji/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dickr/algorithm/wa_jue_ji /Users/dickr/algorithm/wa_jue_ji /Users/dickr/algorithm/wa_jue_ji/cmake-build-debug /Users/dickr/algorithm/wa_jue_ji/cmake-build-debug /Users/dickr/algorithm/wa_jue_ji/cmake-build-debug/CMakeFiles/wa_jue_ji.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wa_jue_ji.dir/depend

