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
CMAKE_SOURCE_DIR = /home/clesson/Projects/MainAlgorithms_Codes/list7/list7A

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/clesson/Projects/MainAlgorithms_Codes/list7/list7A/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/list7A.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/list7A.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/list7A.dir/flags.make

CMakeFiles/list7A.dir/main.cpp.o: CMakeFiles/list7A.dir/flags.make
CMakeFiles/list7A.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/clesson/Projects/MainAlgorithms_Codes/list7/list7A/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/list7A.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/list7A.dir/main.cpp.o -c /home/clesson/Projects/MainAlgorithms_Codes/list7/list7A/main.cpp

CMakeFiles/list7A.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/list7A.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/clesson/Projects/MainAlgorithms_Codes/list7/list7A/main.cpp > CMakeFiles/list7A.dir/main.cpp.i

CMakeFiles/list7A.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/list7A.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/clesson/Projects/MainAlgorithms_Codes/list7/list7A/main.cpp -o CMakeFiles/list7A.dir/main.cpp.s

# Object files for target list7A
list7A_OBJECTS = \
"CMakeFiles/list7A.dir/main.cpp.o"

# External object files for target list7A
list7A_EXTERNAL_OBJECTS =

list7A: CMakeFiles/list7A.dir/main.cpp.o
list7A: CMakeFiles/list7A.dir/build.make
list7A: CMakeFiles/list7A.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/clesson/Projects/MainAlgorithms_Codes/list7/list7A/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable list7A"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/list7A.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/list7A.dir/build: list7A
.PHONY : CMakeFiles/list7A.dir/build

CMakeFiles/list7A.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/list7A.dir/cmake_clean.cmake
.PHONY : CMakeFiles/list7A.dir/clean

CMakeFiles/list7A.dir/depend:
	cd /home/clesson/Projects/MainAlgorithms_Codes/list7/list7A/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/clesson/Projects/MainAlgorithms_Codes/list7/list7A /home/clesson/Projects/MainAlgorithms_Codes/list7/list7A /home/clesson/Projects/MainAlgorithms_Codes/list7/list7A/cmake-build-debug /home/clesson/Projects/MainAlgorithms_Codes/list7/list7A/cmake-build-debug /home/clesson/Projects/MainAlgorithms_Codes/list7/list7A/cmake-build-debug/CMakeFiles/list7A.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/list7A.dir/depend

