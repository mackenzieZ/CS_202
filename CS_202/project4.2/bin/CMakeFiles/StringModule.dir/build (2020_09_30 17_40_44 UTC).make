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
CMAKE_SOURCE_DIR = /mnt/c/Users/Kenzie/CS_202/project4.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Kenzie/CS_202/project4.2/bin

# Include any dependencies generated for this target.
include CMakeFiles/StringModule.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StringModule.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StringModule.dir/flags.make

CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o: CMakeFiles/StringModule.dir/flags.make
CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o: ../src/StringModule/my_string.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Kenzie/CS_202/project4.2/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o -c /mnt/c/Users/Kenzie/CS_202/project4.2/src/StringModule/my_string.cpp

CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Kenzie/CS_202/project4.2/src/StringModule/my_string.cpp > CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.i

CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Kenzie/CS_202/project4.2/src/StringModule/my_string.cpp -o CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.s

CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o.requires:

.PHONY : CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o.requires

CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o.provides: CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o.requires
	$(MAKE) -f CMakeFiles/StringModule.dir/build.make CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o.provides.build
.PHONY : CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o.provides

CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o.provides.build: CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o


# Object files for target StringModule
StringModule_OBJECTS = \
"CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o"

# External object files for target StringModule
StringModule_EXTERNAL_OBJECTS =

libStringModule.a: CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o
libStringModule.a: CMakeFiles/StringModule.dir/build.make
libStringModule.a: CMakeFiles/StringModule.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Kenzie/CS_202/project4.2/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libStringModule.a"
	$(CMAKE_COMMAND) -P CMakeFiles/StringModule.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StringModule.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StringModule.dir/build: libStringModule.a

.PHONY : CMakeFiles/StringModule.dir/build

CMakeFiles/StringModule.dir/requires: CMakeFiles/StringModule.dir/src/StringModule/my_string.cpp.o.requires

.PHONY : CMakeFiles/StringModule.dir/requires

CMakeFiles/StringModule.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StringModule.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StringModule.dir/clean

CMakeFiles/StringModule.dir/depend:
	cd /mnt/c/Users/Kenzie/CS_202/project4.2/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Kenzie/CS_202/project4.2 /mnt/c/Users/Kenzie/CS_202/project4.2 /mnt/c/Users/Kenzie/CS_202/project4.2/bin /mnt/c/Users/Kenzie/CS_202/project4.2/bin /mnt/c/Users/Kenzie/CS_202/project4.2/bin/CMakeFiles/StringModule.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StringModule.dir/depend
