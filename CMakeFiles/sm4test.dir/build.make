# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /mnt/d/work/osCOMP/proj166-gmssl-on-freertos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/work/osCOMP/proj166-gmssl-on-freertos

# Include any dependencies generated for this target.
include CMakeFiles/sm4test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sm4test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sm4test.dir/flags.make

CMakeFiles/sm4test.dir/test/sm4test.c.o: CMakeFiles/sm4test.dir/flags.make
CMakeFiles/sm4test.dir/test/sm4test.c.o: test/sm4test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/work/osCOMP/proj166-gmssl-on-freertos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sm4test.dir/test/sm4test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sm4test.dir/test/sm4test.c.o   -c /mnt/d/work/osCOMP/proj166-gmssl-on-freertos/test/sm4test.c

CMakeFiles/sm4test.dir/test/sm4test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sm4test.dir/test/sm4test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/work/osCOMP/proj166-gmssl-on-freertos/test/sm4test.c > CMakeFiles/sm4test.dir/test/sm4test.c.i

CMakeFiles/sm4test.dir/test/sm4test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sm4test.dir/test/sm4test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/work/osCOMP/proj166-gmssl-on-freertos/test/sm4test.c -o CMakeFiles/sm4test.dir/test/sm4test.c.s

# Object files for target sm4test
sm4test_OBJECTS = \
"CMakeFiles/sm4test.dir/test/sm4test.c.o"

# External object files for target sm4test
sm4test_EXTERNAL_OBJECTS =

bin/sm4test: CMakeFiles/sm4test.dir/test/sm4test.c.o
bin/sm4test: CMakeFiles/sm4test.dir/build.make
bin/sm4test: lib/libgmssl.a
bin/sm4test: CMakeFiles/sm4test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/work/osCOMP/proj166-gmssl-on-freertos/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/sm4test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sm4test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sm4test.dir/build: bin/sm4test

.PHONY : CMakeFiles/sm4test.dir/build

CMakeFiles/sm4test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sm4test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sm4test.dir/clean

CMakeFiles/sm4test.dir/depend:
	cd /mnt/d/work/osCOMP/proj166-gmssl-on-freertos && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/work/osCOMP/proj166-gmssl-on-freertos /mnt/d/work/osCOMP/proj166-gmssl-on-freertos /mnt/d/work/osCOMP/proj166-gmssl-on-freertos /mnt/d/work/osCOMP/proj166-gmssl-on-freertos /mnt/d/work/osCOMP/proj166-gmssl-on-freertos/CMakeFiles/sm4test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sm4test.dir/depend
