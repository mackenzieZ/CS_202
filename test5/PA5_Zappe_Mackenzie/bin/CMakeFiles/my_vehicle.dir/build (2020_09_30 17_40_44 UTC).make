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
CMAKE_SOURCE_DIR = /mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie/bin

# Include any dependencies generated for this target.
include CMakeFiles/my_vehicle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_vehicle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_vehicle.dir/flags.make

CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o: CMakeFiles/my_vehicle.dir/flags.make
CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o: ../src/my_vehicle/vehicle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o -c /mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie/src/my_vehicle/vehicle.cpp

CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie/src/my_vehicle/vehicle.cpp > CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.i

CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie/src/my_vehicle/vehicle.cpp -o CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.s

CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o.requires:

.PHONY : CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o.requires

CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o.provides: CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o.requires
	$(MAKE) -f CMakeFiles/my_vehicle.dir/build.make CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o.provides.build
.PHONY : CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o.provides

CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o.provides.build: CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o


# Object files for target my_vehicle
my_vehicle_OBJECTS = \
"CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o"

# External object files for target my_vehicle
my_vehicle_EXTERNAL_OBJECTS =

libmy_vehicle.a: CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o
libmy_vehicle.a: CMakeFiles/my_vehicle.dir/build.make
libmy_vehicle.a: CMakeFiles/my_vehicle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmy_vehicle.a"
	$(CMAKE_COMMAND) -P CMakeFiles/my_vehicle.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_vehicle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_vehicle.dir/build: libmy_vehicle.a

.PHONY : CMakeFiles/my_vehicle.dir/build

CMakeFiles/my_vehicle.dir/requires: CMakeFiles/my_vehicle.dir/src/my_vehicle/vehicle.cpp.o.requires

.PHONY : CMakeFiles/my_vehicle.dir/requires

CMakeFiles/my_vehicle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_vehicle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_vehicle.dir/clean

CMakeFiles/my_vehicle.dir/depend:
	cd /mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie /mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie /mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie/bin /mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie/bin /mnt/c/Users/Kenzie/CS_202/test5/PA5_Zappe_Mackenzie/bin/CMakeFiles/my_vehicle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_vehicle.dir/depend

