# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/clesson/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/clesson/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/clesson/Projects/MainAlgorithms_Codes/list3/list3B

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/clesson/Projects/MainAlgorithms_Codes/list3/list3B/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/list3B.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/list3B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/list3B.dir/flags.make

CMakeFiles/list3B.dir/main.cpp.o: CMakeFiles/list3B.dir/flags.make
CMakeFiles/list3B.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clesson/Projects/MainAlgorithms_Codes/list3/list3B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/list3B.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/list3B.dir/main.cpp.o -c /home/clesson/Projects/MainAlgorithms_Codes/list3/list3B/main.cpp

CMakeFiles/list3B.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/list3B.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clesson/Projects/MainAlgorithms_Codes/list3/list3B/main.cpp > CMakeFiles/list3B.dir/main.cpp.i

CMakeFiles/list3B.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/list3B.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clesson/Projects/MainAlgorithms_Codes/list3/list3B/main.cpp -o CMakeFiles/list3B.dir/main.cpp.s

# Object files for target list3B
list3B_OBJECTS = \
"CMakeFiles/list3B.dir/main.cpp.o"

# External object files for target list3B
list3B_EXTERNAL_OBJECTS =

list3B: CMakeFiles/list3B.dir/main.cpp.o
list3B: CMakeFiles/list3B.dir/build.make
list3B: CMakeFiles/list3B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clesson/Projects/MainAlgorithms_Codes/list3/list3B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable list3B"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/list3B.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/list3B.dir/build: list3B
.PHONY : CMakeFiles/list3B.dir/build

CMakeFiles/list3B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/list3B.dir/cmake_clean.cmake
.PHONY : CMakeFiles/list3B.dir/clean

CMakeFiles/list3B.dir/depend:
	cd /home/clesson/Projects/MainAlgorithms_Codes/list3/list3B/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clesson/Projects/MainAlgorithms_Codes/list3/list3B /home/clesson/Projects/MainAlgorithms_Codes/list3/list3B /home/clesson/Projects/MainAlgorithms_Codes/list3/list3B/cmake-build-debug /home/clesson/Projects/MainAlgorithms_Codes/list3/list3B/cmake-build-debug /home/clesson/Projects/MainAlgorithms_Codes/list3/list3B/cmake-build-debug/CMakeFiles/list3B.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/list3B.dir/depend
