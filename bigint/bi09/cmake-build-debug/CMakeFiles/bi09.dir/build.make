# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bea/ufes/semestre-2/prog2b/bigint/bi09

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bea/ufes/semestre-2/prog2b/bigint/bi09/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bi09.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bi09.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bi09.dir/flags.make

CMakeFiles/bi09.dir/bi09.c.o: CMakeFiles/bi09.dir/flags.make
CMakeFiles/bi09.dir/bi09.c.o: ../bi09.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bea/ufes/semestre-2/prog2b/bigint/bi09/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bi09.dir/bi09.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bi09.dir/bi09.c.o   -c /home/bea/ufes/semestre-2/prog2b/bigint/bi09/bi09.c

CMakeFiles/bi09.dir/bi09.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bi09.dir/bi09.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bea/ufes/semestre-2/prog2b/bigint/bi09/bi09.c > CMakeFiles/bi09.dir/bi09.c.i

CMakeFiles/bi09.dir/bi09.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bi09.dir/bi09.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bea/ufes/semestre-2/prog2b/bigint/bi09/bi09.c -o CMakeFiles/bi09.dir/bi09.c.s

# Object files for target bi09
bi09_OBJECTS = \
"CMakeFiles/bi09.dir/bi09.c.o"

# External object files for target bi09
bi09_EXTERNAL_OBJECTS =

bi09: CMakeFiles/bi09.dir/bi09.c.o
bi09: CMakeFiles/bi09.dir/build.make
bi09: CMakeFiles/bi09.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bea/ufes/semestre-2/prog2b/bigint/bi09/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bi09"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bi09.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bi09.dir/build: bi09

.PHONY : CMakeFiles/bi09.dir/build

CMakeFiles/bi09.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bi09.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bi09.dir/clean

CMakeFiles/bi09.dir/depend:
	cd /home/bea/ufes/semestre-2/prog2b/bigint/bi09/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bea/ufes/semestre-2/prog2b/bigint/bi09 /home/bea/ufes/semestre-2/prog2b/bigint/bi09 /home/bea/ufes/semestre-2/prog2b/bigint/bi09/cmake-build-debug /home/bea/ufes/semestre-2/prog2b/bigint/bi09/cmake-build-debug /home/bea/ufes/semestre-2/prog2b/bigint/bi09/cmake-build-debug/CMakeFiles/bi09.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bi09.dir/depend

