# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Programing\Code\C\C_vsc\hospital_management

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Programing\Code\C\C_vsc\hospital_management\build

# Include any dependencies generated for this target.
include CMakeFiles/main.exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.exe.dir/flags.make

CMakeFiles/main.exe.dir/main.c.obj: CMakeFiles/main.exe.dir/flags.make
CMakeFiles/main.exe.dir/main.c.obj: CMakeFiles/main.exe.dir/includes_C.rsp
CMakeFiles/main.exe.dir/main.c.obj: D:/Programing/Code/C/C_vsc/hospital_management/main.c
CMakeFiles/main.exe.dir/main.c.obj: CMakeFiles/main.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programing\Code\C\C_vsc\hospital_management\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.exe.dir/main.c.obj"
	D:\Programing\Environment\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.exe.dir/main.c.obj -MF CMakeFiles\main.exe.dir\main.c.obj.d -o CMakeFiles\main.exe.dir\main.c.obj -c D:\Programing\Code\C\C_vsc\hospital_management\main.c

CMakeFiles/main.exe.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.exe.dir/main.c.i"
	D:\Programing\Environment\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Programing\Code\C\C_vsc\hospital_management\main.c > CMakeFiles\main.exe.dir\main.c.i

CMakeFiles/main.exe.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.exe.dir/main.c.s"
	D:\Programing\Environment\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Programing\Code\C\C_vsc\hospital_management\main.c -o CMakeFiles\main.exe.dir\main.c.s

# Object files for target main.exe
main_exe_OBJECTS = \
"CMakeFiles/main.exe.dir/main.c.obj"

# External object files for target main.exe
main_exe_EXTERNAL_OBJECTS =

main.exe.exe: CMakeFiles/main.exe.dir/main.c.obj
main.exe.exe: CMakeFiles/main.exe.dir/build.make
main.exe.exe: CMakeFiles/main.exe.dir/linkLibs.rsp
main.exe.exe: CMakeFiles/main.exe.dir/objects1.rsp
main.exe.exe: CMakeFiles/main.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Programing\Code\C\C_vsc\hospital_management\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable main.exe.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.exe.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.exe.dir/build: main.exe.exe
.PHONY : CMakeFiles/main.exe.dir/build

CMakeFiles/main.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\main.exe.dir\cmake_clean.cmake
.PHONY : CMakeFiles/main.exe.dir/clean

CMakeFiles/main.exe.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Programing\Code\C\C_vsc\hospital_management D:\Programing\Code\C\C_vsc\hospital_management D:\Programing\Code\C\C_vsc\hospital_management\build D:\Programing\Code\C\C_vsc\hospital_management\build D:\Programing\Code\C\C_vsc\hospital_management\build\CMakeFiles\main.exe.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.exe.dir/depend

