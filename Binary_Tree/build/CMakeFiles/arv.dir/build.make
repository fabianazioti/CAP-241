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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree/build

# Include any dependencies generated for this target.
include CMakeFiles/arv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/arv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arv.dir/flags.make

CMakeFiles/arv.dir/src/main.cpp.o: CMakeFiles/arv.dir/flags.make
CMakeFiles/arv.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/arv.dir/src/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arv.dir/src/main.cpp.o -c /home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree/src/main.cpp

CMakeFiles/arv.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arv.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree/src/main.cpp > CMakeFiles/arv.dir/src/main.cpp.i

CMakeFiles/arv.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arv.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree/src/main.cpp -o CMakeFiles/arv.dir/src/main.cpp.s

CMakeFiles/arv.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/arv.dir/src/main.cpp.o.requires

CMakeFiles/arv.dir/src/main.cpp.o.provides: CMakeFiles/arv.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/arv.dir/build.make CMakeFiles/arv.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/arv.dir/src/main.cpp.o.provides

CMakeFiles/arv.dir/src/main.cpp.o.provides.build: CMakeFiles/arv.dir/src/main.cpp.o


# Object files for target arv
arv_OBJECTS = \
"CMakeFiles/arv.dir/src/main.cpp.o"

# External object files for target arv
arv_EXTERNAL_OBJECTS =

arv: CMakeFiles/arv.dir/src/main.cpp.o
arv: CMakeFiles/arv.dir/build.make
arv: CMakeFiles/arv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable arv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arv.dir/build: arv

.PHONY : CMakeFiles/arv.dir/build

CMakeFiles/arv.dir/requires: CMakeFiles/arv.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/arv.dir/requires

CMakeFiles/arv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arv.dir/clean

CMakeFiles/arv.dir/depend:
	cd /home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree /home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree /home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree/build /home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree/build /home/fabiana/Documentos/INPE/devel/github/CAP-241/Binary_Tree/build/CMakeFiles/arv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arv.dir/depend

