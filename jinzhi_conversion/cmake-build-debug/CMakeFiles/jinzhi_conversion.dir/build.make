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
CMAKE_SOURCE_DIR = /Users/dickr/algorithm/jinzhi_conversion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dickr/algorithm/jinzhi_conversion/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/jinzhi_conversion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/jinzhi_conversion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/jinzhi_conversion.dir/flags.make

CMakeFiles/jinzhi_conversion.dir/main.cpp.o: CMakeFiles/jinzhi_conversion.dir/flags.make
CMakeFiles/jinzhi_conversion.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dickr/algorithm/jinzhi_conversion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/jinzhi_conversion.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jinzhi_conversion.dir/main.cpp.o -c /Users/dickr/algorithm/jinzhi_conversion/main.cpp

CMakeFiles/jinzhi_conversion.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jinzhi_conversion.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dickr/algorithm/jinzhi_conversion/main.cpp > CMakeFiles/jinzhi_conversion.dir/main.cpp.i

CMakeFiles/jinzhi_conversion.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jinzhi_conversion.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dickr/algorithm/jinzhi_conversion/main.cpp -o CMakeFiles/jinzhi_conversion.dir/main.cpp.s

# Object files for target jinzhi_conversion
jinzhi_conversion_OBJECTS = \
"CMakeFiles/jinzhi_conversion.dir/main.cpp.o"

# External object files for target jinzhi_conversion
jinzhi_conversion_EXTERNAL_OBJECTS =

jinzhi_conversion: CMakeFiles/jinzhi_conversion.dir/main.cpp.o
jinzhi_conversion: CMakeFiles/jinzhi_conversion.dir/build.make
jinzhi_conversion: CMakeFiles/jinzhi_conversion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dickr/algorithm/jinzhi_conversion/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable jinzhi_conversion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jinzhi_conversion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/jinzhi_conversion.dir/build: jinzhi_conversion

.PHONY : CMakeFiles/jinzhi_conversion.dir/build

CMakeFiles/jinzhi_conversion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/jinzhi_conversion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/jinzhi_conversion.dir/clean

CMakeFiles/jinzhi_conversion.dir/depend:
	cd /Users/dickr/algorithm/jinzhi_conversion/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dickr/algorithm/jinzhi_conversion /Users/dickr/algorithm/jinzhi_conversion /Users/dickr/algorithm/jinzhi_conversion/cmake-build-debug /Users/dickr/algorithm/jinzhi_conversion/cmake-build-debug /Users/dickr/algorithm/jinzhi_conversion/cmake-build-debug/CMakeFiles/jinzhi_conversion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jinzhi_conversion.dir/depend
