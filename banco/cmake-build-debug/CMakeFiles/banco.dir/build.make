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
CMAKE_SOURCE_DIR = /home/bea/ufes/semestre-2/prog2b/banco

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bea/ufes/semestre-2/prog2b/banco/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/banco.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/banco.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/banco.dir/flags.make

CMakeFiles/banco.dir/new_bank.c.o: CMakeFiles/banco.dir/flags.make
CMakeFiles/banco.dir/new_bank.c.o: ../new_bank.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bea/ufes/semestre-2/prog2b/banco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/banco.dir/new_bank.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/banco.dir/new_bank.c.o   -c /home/bea/ufes/semestre-2/prog2b/banco/new_bank.c

CMakeFiles/banco.dir/new_bank.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/banco.dir/new_bank.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bea/ufes/semestre-2/prog2b/banco/new_bank.c > CMakeFiles/banco.dir/new_bank.c.i

CMakeFiles/banco.dir/new_bank.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/banco.dir/new_bank.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bea/ufes/semestre-2/prog2b/banco/new_bank.c -o CMakeFiles/banco.dir/new_bank.c.s

# Object files for target banco
banco_OBJECTS = \
"CMakeFiles/banco.dir/new_bank.c.o"

# External object files for target banco
banco_EXTERNAL_OBJECTS =

banco: CMakeFiles/banco.dir/new_bank.c.o
banco: CMakeFiles/banco.dir/build.make
banco: CMakeFiles/banco.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bea/ufes/semestre-2/prog2b/banco/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable banco"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/banco.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/banco.dir/build: banco

.PHONY : CMakeFiles/banco.dir/build

CMakeFiles/banco.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/banco.dir/cmake_clean.cmake
.PHONY : CMakeFiles/banco.dir/clean

CMakeFiles/banco.dir/depend:
	cd /home/bea/ufes/semestre-2/prog2b/banco/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bea/ufes/semestre-2/prog2b/banco /home/bea/ufes/semestre-2/prog2b/banco /home/bea/ufes/semestre-2/prog2b/banco/cmake-build-debug /home/bea/ufes/semestre-2/prog2b/banco/cmake-build-debug /home/bea/ufes/semestre-2/prog2b/banco/cmake-build-debug/CMakeFiles/banco.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/banco.dir/depend

