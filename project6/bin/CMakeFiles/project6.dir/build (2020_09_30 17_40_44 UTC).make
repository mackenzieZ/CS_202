# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /mnt/c/Users/Kenzie/CS_202/project6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Kenzie/CS_202/project6/bin

# Include any dependencies generated for this target.
include CMakeFiles/project6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project6.dir/flags.make

CMakeFiles/project6.dir/src/proj6.cpp.o: CMakeFiles/project6.dir/flags.make
CMakeFiles/project6.dir/src/proj6.cpp.o: ../src/proj6.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Kenzie/CS_202/project6/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project6.dir/src/proj6.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/project6.dir/src/proj6.cpp.o -c /mnt/c/Users/Kenzie/CS_202/project6/src/proj6.cpp

CMakeFiles/project6.dir/src/proj6.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project6.dir/src/proj6.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Kenzie/CS_202/project6/src/proj6.cpp > CMakeFiles/project6.dir/src/proj6.cpp.i

CMakeFiles/project6.dir/src/proj6.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project6.dir/src/proj6.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Kenzie/CS_202/project6/src/proj6.cpp -o CMakeFiles/project6.dir/src/proj6.cpp.s

CMakeFiles/project6.dir/src/proj6.cpp.o.requires:

.PHONY : CMakeFiles/project6.dir/src/proj6.cpp.o.requires

CMakeFiles/project6.dir/src/proj6.cpp.o.provides: CMakeFiles/project6.dir/src/proj6.cpp.o.requires
	$(MAKE) -f CMakeFiles/project6.dir/build.make CMakeFiles/project6.dir/src/proj6.cpp.o.provides.build
.PHONY : CMakeFiles/project6.dir/src/proj6.cpp.o.provides

CMakeFiles/project6.dir/src/proj6.cpp.o.provides.build: CMakeFiles/project6.dir/src/proj6.cpp.o


# Object files for target project6
project6_OBJECTS = \
"CMakeFiles/project6.dir/src/proj6.cpp.o"

# External object files for target project6
project6_EXTERNAL_OBJECTS =

project6: CMakeFiles/project6.dir/src/proj6.cpp.o
project6: CMakeFiles/project6.dir/build.make
project6: libmy_vehicle.a
project6: libmy_car.a
project6: CMakeFiles/project6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Kenzie/CS_202/project6/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable project6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project6.dir/build: project6

.PHONY : CMakeFiles/project6.dir/build

CMakeFiles/project6.dir/requires: CMakeFiles/project6.dir/src/proj6.cpp.o.requires

.PHONY : CMakeFiles/project6.dir/requires

CMakeFiles/project6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project6.dir/clean

CMakeFiles/project6.dir/depend:
	cd /mnt/c/Users/Kenzie/CS_202/project6/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Kenzie/CS_202/project6 /mnt/c/Users/Kenzie/CS_202/project6 /mnt/c/Users/Kenzie/CS_202/project6/bin /mnt/c/Users/Kenzie/CS_202/project6/bin /mnt/c/Users/Kenzie/CS_202/project6/bin/CMakeFiles/project6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project6.dir/depend

