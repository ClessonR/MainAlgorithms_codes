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
CMAKE_COMMAND = /home/clesson/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/clesson/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/clesson/Projects/MainAlgorithms_Codes/list4/list4B

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/clesson/Projects/MainAlgorithms_Codes/list4/list4B/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/list4B.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/list4B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/list4B.dir/flags.make

CMakeFiles/list4B.dir/main.cpp.o: CMakeFiles/list4B.dir/flags.make
CMakeFiles/list4B.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clesson/Projects/MainAlgorithms_Codes/list4/list4B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/list4B.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/list4B.dir/main.cpp.o -c /home/clesson/Projects/MainAlgorithms_Codes/list4/list4B/main.cpp

CMakeFiles/list4B.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/list4B.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clesson/Projects/MainAlgorithms_Codes/list4/list4B/main.cpp > CMakeFiles/list4B.dir/main.cpp.i

CMakeFiles/list4B.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/list4B.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clesson/Projects/MainAlgorithms_Codes/list4/list4B/main.cpp -o CMakeFiles/list4B.dir/main.cpp.s

# Object files for target list4B
list4B_OBJECTS = \
"CMakeFiles/list4B.dir/main.cpp.o"

# External object files for target list4B
list4B_EXTERNAL_OBJECTS =

list4B: CMakeFiles/list4B.dir/main.cpp.o
list4B: CMakeFiles/list4B.dir/build.make
list4B: CMakeFiles/list4B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clesson/Projects/MainAlgorithms_Codes/list4/list4B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable list4B"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/list4B.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/list4B.dir/build: list4B
.PHONY : CMakeFiles/list4B.dir/build

CMakeFiles/list4B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/list4B.dir/cmake_clean.cmake
.PHONY : CMakeFiles/list4B.dir/clean

CMakeFiles/list4B.dir/depend:
	cd /home/clesson/Projects/MainAlgorithms_Codes/list4/list4B/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clesson/Projects/MainAlgorithms_Codes/list4/list4B /home/clesson/Projects/MainAlgorithms_Codes/list4/list4B /home/clesson/Projects/MainAlgorithms_Codes/list4/list4B/cmake-build-debug /home/clesson/Projects/MainAlgorithms_Codes/list4/list4B/cmake-build-debug /home/clesson/Projects/MainAlgorithms_Codes/list4/list4B/cmake-build-debug/CMakeFiles/list4B.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/list4B.dir/depend

