# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Programm\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Programm\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\haysa\CLionProjects\accessSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\haysa\CLionProjects\accessSystem\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/accessSystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/accessSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/accessSystem.dir/flags.make

CMakeFiles/accessSystem.dir/main.cpp.obj: CMakeFiles/accessSystem.dir/flags.make
CMakeFiles/accessSystem.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\haysa\CLionProjects\accessSystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/accessSystem.dir/main.cpp.obj"
	C:\Programm\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\accessSystem.dir\main.cpp.obj -c C:\Users\haysa\CLionProjects\accessSystem\main.cpp

CMakeFiles/accessSystem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/accessSystem.dir/main.cpp.i"
	C:\Programm\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\haysa\CLionProjects\accessSystem\main.cpp > CMakeFiles\accessSystem.dir\main.cpp.i

CMakeFiles/accessSystem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/accessSystem.dir/main.cpp.s"
	C:\Programm\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\haysa\CLionProjects\accessSystem\main.cpp -o CMakeFiles\accessSystem.dir\main.cpp.s

# Object files for target accessSystem
accessSystem_OBJECTS = \
"CMakeFiles/accessSystem.dir/main.cpp.obj"

# External object files for target accessSystem
accessSystem_EXTERNAL_OBJECTS =

accessSystem.exe: CMakeFiles/accessSystem.dir/main.cpp.obj
accessSystem.exe: CMakeFiles/accessSystem.dir/build.make
accessSystem.exe: CMakeFiles/accessSystem.dir/linklibs.rsp
accessSystem.exe: CMakeFiles/accessSystem.dir/objects1.rsp
accessSystem.exe: CMakeFiles/accessSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\haysa\CLionProjects\accessSystem\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable accessSystem.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\accessSystem.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/accessSystem.dir/build: accessSystem.exe

.PHONY : CMakeFiles/accessSystem.dir/build

CMakeFiles/accessSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\accessSystem.dir\cmake_clean.cmake
.PHONY : CMakeFiles/accessSystem.dir/clean

CMakeFiles/accessSystem.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\haysa\CLionProjects\accessSystem C:\Users\haysa\CLionProjects\accessSystem C:\Users\haysa\CLionProjects\accessSystem\cmake-build-debug C:\Users\haysa\CLionProjects\accessSystem\cmake-build-debug C:\Users\haysa\CLionProjects\accessSystem\cmake-build-debug\CMakeFiles\accessSystem.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/accessSystem.dir/depend

