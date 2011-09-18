# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.6

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/build

# Include any dependencies generated for this target.
include heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/depend.make

# Include the progress variables for this target.
include heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/progress.make

# Include the compile flags for this target's objects.
include heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/flags.make

heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o: heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/flags.make
heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o: ../heuristics/hdoghmen/KillerHeuristic.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o"
	cd /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/build/heuristics && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -fPIC -o CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o -c /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/heuristics/hdoghmen/KillerHeuristic.cpp

heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.i"
	cd /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/build/heuristics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -fPIC -E /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/heuristics/hdoghmen/KillerHeuristic.cpp > CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.i

heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.s"
	cd /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/build/heuristics && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -fPIC -S /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/heuristics/hdoghmen/KillerHeuristic.cpp -o CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.s

heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o.requires:
.PHONY : heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o.requires

heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o.provides: heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o.requires
	$(MAKE) -f heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/build.make heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o.provides.build
.PHONY : heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o.provides

heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o.provides.build: heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o
.PHONY : heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o.provides.build

# Object files for target heuristic-hdoghmen-KillerHeuristic
heuristic__hdoghmen__KillerHeuristic_OBJECTS = \
"CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o"

# External object files for target heuristic-hdoghmen-KillerHeuristic
heuristic__hdoghmen__KillerHeuristic_EXTERNAL_OBJECTS =

bin/heuristics/hdoghmen/libKillerHeuristic.so: heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o
bin/heuristics/hdoghmen/libKillerHeuristic.so: bin/libmash-core.so
bin/heuristics/hdoghmen/libKillerHeuristic.so: bin/libmash-utils.so
bin/heuristics/hdoghmen/libKillerHeuristic.so: lib/libfreeimage.a
bin/heuristics/hdoghmen/libKillerHeuristic.so: heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/build.make
bin/heuristics/hdoghmen/libKillerHeuristic.so: heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared module ../bin/heuristics/hdoghmen/libKillerHeuristic.so"
	cd /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/build/heuristics && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/build: bin/heuristics/hdoghmen/libKillerHeuristic.so
.PHONY : heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/build

heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/requires: heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/hdoghmen/KillerHeuristic.cpp.o.requires
.PHONY : heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/requires

heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/clean:
	cd /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/build/heuristics && $(CMAKE_COMMAND) -P CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/cmake_clean.cmake
.PHONY : heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/clean

heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/depend:
	cd /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0 /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/heuristics /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/build /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/build/heuristics /users/tao/doghmen/Algorithms-implementation/mash_sdk_1.0.0/build/heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : heuristics/CMakeFiles/heuristic-hdoghmen-KillerHeuristic.dir/depend

