# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gui/projetoSO-1/4-7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gui/projetoSO-1/4-7/build

# Include any dependencies generated for this target.
include CMakeFiles/application.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/application.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/application.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/application.dir/flags.make

CMakeFiles/application.dir/src/main.c.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/main.c.o: /home/gui/projetoSO-1/4-7/src/main.c
CMakeFiles/application.dir/src/main.c.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gui/projetoSO-1/4-7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/application.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/application.dir/src/main.c.o -MF CMakeFiles/application.dir/src/main.c.o.d -o CMakeFiles/application.dir/src/main.c.o -c /home/gui/projetoSO-1/4-7/src/main.c

CMakeFiles/application.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/application.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gui/projetoSO-1/4-7/src/main.c > CMakeFiles/application.dir/src/main.c.i

CMakeFiles/application.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/application.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gui/projetoSO-1/4-7/src/main.c -o CMakeFiles/application.dir/src/main.c.s

CMakeFiles/application.dir/src/file_reader.c.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/file_reader.c.o: /home/gui/projetoSO-1/4-7/src/file_reader.c
CMakeFiles/application.dir/src/file_reader.c.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gui/projetoSO-1/4-7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/application.dir/src/file_reader.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/application.dir/src/file_reader.c.o -MF CMakeFiles/application.dir/src/file_reader.c.o.d -o CMakeFiles/application.dir/src/file_reader.c.o -c /home/gui/projetoSO-1/4-7/src/file_reader.c

CMakeFiles/application.dir/src/file_reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/application.dir/src/file_reader.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gui/projetoSO-1/4-7/src/file_reader.c > CMakeFiles/application.dir/src/file_reader.c.i

CMakeFiles/application.dir/src/file_reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/application.dir/src/file_reader.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gui/projetoSO-1/4-7/src/file_reader.c -o CMakeFiles/application.dir/src/file_reader.c.s

CMakeFiles/application.dir/src/tree_view.c.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/tree_view.c.o: /home/gui/projetoSO-1/4-7/src/tree_view.c
CMakeFiles/application.dir/src/tree_view.c.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gui/projetoSO-1/4-7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/application.dir/src/tree_view.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/application.dir/src/tree_view.c.o -MF CMakeFiles/application.dir/src/tree_view.c.o.d -o CMakeFiles/application.dir/src/tree_view.c.o -c /home/gui/projetoSO-1/4-7/src/tree_view.c

CMakeFiles/application.dir/src/tree_view.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/application.dir/src/tree_view.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gui/projetoSO-1/4-7/src/tree_view.c > CMakeFiles/application.dir/src/tree_view.c.i

CMakeFiles/application.dir/src/tree_view.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/application.dir/src/tree_view.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gui/projetoSO-1/4-7/src/tree_view.c -o CMakeFiles/application.dir/src/tree_view.c.s

CMakeFiles/application.dir/src/widgets.c.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/widgets.c.o: /home/gui/projetoSO-1/4-7/src/widgets.c
CMakeFiles/application.dir/src/widgets.c.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gui/projetoSO-1/4-7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/application.dir/src/widgets.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/application.dir/src/widgets.c.o -MF CMakeFiles/application.dir/src/widgets.c.o.d -o CMakeFiles/application.dir/src/widgets.c.o -c /home/gui/projetoSO-1/4-7/src/widgets.c

CMakeFiles/application.dir/src/widgets.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/application.dir/src/widgets.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gui/projetoSO-1/4-7/src/widgets.c > CMakeFiles/application.dir/src/widgets.c.i

CMakeFiles/application.dir/src/widgets.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/application.dir/src/widgets.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gui/projetoSO-1/4-7/src/widgets.c -o CMakeFiles/application.dir/src/widgets.c.s

CMakeFiles/application.dir/src/functions.c.o: CMakeFiles/application.dir/flags.make
CMakeFiles/application.dir/src/functions.c.o: /home/gui/projetoSO-1/4-7/src/functions.c
CMakeFiles/application.dir/src/functions.c.o: CMakeFiles/application.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gui/projetoSO-1/4-7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/application.dir/src/functions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/application.dir/src/functions.c.o -MF CMakeFiles/application.dir/src/functions.c.o.d -o CMakeFiles/application.dir/src/functions.c.o -c /home/gui/projetoSO-1/4-7/src/functions.c

CMakeFiles/application.dir/src/functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/application.dir/src/functions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gui/projetoSO-1/4-7/src/functions.c > CMakeFiles/application.dir/src/functions.c.i

CMakeFiles/application.dir/src/functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/application.dir/src/functions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gui/projetoSO-1/4-7/src/functions.c -o CMakeFiles/application.dir/src/functions.c.s

# Object files for target application
application_OBJECTS = \
"CMakeFiles/application.dir/src/main.c.o" \
"CMakeFiles/application.dir/src/file_reader.c.o" \
"CMakeFiles/application.dir/src/tree_view.c.o" \
"CMakeFiles/application.dir/src/widgets.c.o" \
"CMakeFiles/application.dir/src/functions.c.o"

# External object files for target application
application_EXTERNAL_OBJECTS =

bin/application: CMakeFiles/application.dir/src/main.c.o
bin/application: CMakeFiles/application.dir/src/file_reader.c.o
bin/application: CMakeFiles/application.dir/src/tree_view.c.o
bin/application: CMakeFiles/application.dir/src/widgets.c.o
bin/application: CMakeFiles/application.dir/src/functions.c.o
bin/application: CMakeFiles/application.dir/build.make
bin/application: CMakeFiles/application.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gui/projetoSO-1/4-7/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable bin/application"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/application.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E create_symlink /home/gui/projetoSO-1/4-7/glade /home/gui/projetoSO-1/4-7/build/bin/glade

# Rule to build all files generated by this target.
CMakeFiles/application.dir/build: bin/application
.PHONY : CMakeFiles/application.dir/build

CMakeFiles/application.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/application.dir/cmake_clean.cmake
.PHONY : CMakeFiles/application.dir/clean

CMakeFiles/application.dir/depend:
	cd /home/gui/projetoSO-1/4-7/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gui/projetoSO-1/4-7 /home/gui/projetoSO-1/4-7 /home/gui/projetoSO-1/4-7/build /home/gui/projetoSO-1/4-7/build /home/gui/projetoSO-1/4-7/build/CMakeFiles/application.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/application.dir/depend

