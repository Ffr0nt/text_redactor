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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/fedor/CLionProjects/text_redactor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fedor/CLionProjects/text_redactor/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/text_redactor.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/text_redactor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/text_redactor.dir/flags.make

CMakeFiles/text_redactor.dir/main.cpp.o: CMakeFiles/text_redactor.dir/flags.make
CMakeFiles/text_redactor.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fedor/CLionProjects/text_redactor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/text_redactor.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/text_redactor.dir/main.cpp.o -c /Users/fedor/CLionProjects/text_redactor/main.cpp

CMakeFiles/text_redactor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/text_redactor.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fedor/CLionProjects/text_redactor/main.cpp > CMakeFiles/text_redactor.dir/main.cpp.i

CMakeFiles/text_redactor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/text_redactor.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fedor/CLionProjects/text_redactor/main.cpp -o CMakeFiles/text_redactor.dir/main.cpp.s

CMakeFiles/text_redactor.dir/Document.cpp.o: CMakeFiles/text_redactor.dir/flags.make
CMakeFiles/text_redactor.dir/Document.cpp.o: Document.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fedor/CLionProjects/text_redactor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/text_redactor.dir/Document.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/text_redactor.dir/Document.cpp.o -c /Users/fedor/CLionProjects/text_redactor/cmake-build-debug/Document.cpp

CMakeFiles/text_redactor.dir/Document.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/text_redactor.dir/Document.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fedor/CLionProjects/text_redactor/cmake-build-debug/Document.cpp > CMakeFiles/text_redactor.dir/Document.cpp.i

CMakeFiles/text_redactor.dir/Document.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/text_redactor.dir/Document.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fedor/CLionProjects/text_redactor/cmake-build-debug/Document.cpp -o CMakeFiles/text_redactor.dir/Document.cpp.s

# Object files for target text_redactor
text_redactor_OBJECTS = \
"CMakeFiles/text_redactor.dir/main.cpp.o" \
"CMakeFiles/text_redactor.dir/Document.cpp.o"

# External object files for target text_redactor
text_redactor_EXTERNAL_OBJECTS =

text_redactor: CMakeFiles/text_redactor.dir/main.cpp.o
text_redactor: CMakeFiles/text_redactor.dir/Document.cpp.o
text_redactor: CMakeFiles/text_redactor.dir/build.make
text_redactor: CMakeFiles/text_redactor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/fedor/CLionProjects/text_redactor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable text_redactor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/text_redactor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/text_redactor.dir/build: text_redactor
.PHONY : CMakeFiles/text_redactor.dir/build

CMakeFiles/text_redactor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/text_redactor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/text_redactor.dir/clean

CMakeFiles/text_redactor.dir/depend:
	cd /Users/fedor/CLionProjects/text_redactor/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fedor/CLionProjects/text_redactor /Users/fedor/CLionProjects/text_redactor /Users/fedor/CLionProjects/text_redactor/cmake-build-debug /Users/fedor/CLionProjects/text_redactor/cmake-build-debug /Users/fedor/CLionProjects/text_redactor/cmake-build-debug/CMakeFiles/text_redactor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/text_redactor.dir/depend
