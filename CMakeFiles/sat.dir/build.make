# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.5

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\git\libsat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\git\libsat

# Include any dependencies generated for this target.
include CMakeFiles/sat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sat.dir/flags.make

CMakeFiles/sat.dir/libsat.cpp.obj: CMakeFiles/sat.dir/flags.make
CMakeFiles/sat.dir/libsat.cpp.obj: libsat.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\libsat\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sat.dir/libsat.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sat.dir\libsat.cpp.obj -c D:\git\libsat\libsat.cpp

CMakeFiles/sat.dir/libsat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sat.dir/libsat.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\libsat\libsat.cpp > CMakeFiles\sat.dir\libsat.cpp.i

CMakeFiles/sat.dir/libsat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sat.dir/libsat.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\libsat\libsat.cpp -o CMakeFiles\sat.dir\libsat.cpp.s

CMakeFiles/sat.dir/libsat.cpp.obj.requires:

.PHONY : CMakeFiles/sat.dir/libsat.cpp.obj.requires

CMakeFiles/sat.dir/libsat.cpp.obj.provides: CMakeFiles/sat.dir/libsat.cpp.obj.requires
	$(MAKE) -f CMakeFiles\sat.dir\build.make CMakeFiles/sat.dir/libsat.cpp.obj.provides.build
.PHONY : CMakeFiles/sat.dir/libsat.cpp.obj.provides

CMakeFiles/sat.dir/libsat.cpp.obj.provides.build: CMakeFiles/sat.dir/libsat.cpp.obj


CMakeFiles/sat.dir/satvector.cpp.obj: CMakeFiles/sat.dir/flags.make
CMakeFiles/sat.dir/satvector.cpp.obj: satvector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\libsat\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sat.dir/satvector.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sat.dir\satvector.cpp.obj -c D:\git\libsat\satvector.cpp

CMakeFiles/sat.dir/satvector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sat.dir/satvector.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\libsat\satvector.cpp > CMakeFiles\sat.dir\satvector.cpp.i

CMakeFiles/sat.dir/satvector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sat.dir/satvector.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\libsat\satvector.cpp -o CMakeFiles\sat.dir\satvector.cpp.s

CMakeFiles/sat.dir/satvector.cpp.obj.requires:

.PHONY : CMakeFiles/sat.dir/satvector.cpp.obj.requires

CMakeFiles/sat.dir/satvector.cpp.obj.provides: CMakeFiles/sat.dir/satvector.cpp.obj.requires
	$(MAKE) -f CMakeFiles\sat.dir\build.make CMakeFiles/sat.dir/satvector.cpp.obj.provides.build
.PHONY : CMakeFiles/sat.dir/satvector.cpp.obj.provides

CMakeFiles/sat.dir/satvector.cpp.obj.provides.build: CMakeFiles/sat.dir/satvector.cpp.obj


CMakeFiles/sat.dir/satcircle.cpp.obj: CMakeFiles/sat.dir/flags.make
CMakeFiles/sat.dir/satcircle.cpp.obj: satcircle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\libsat\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sat.dir/satcircle.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sat.dir\satcircle.cpp.obj -c D:\git\libsat\satcircle.cpp

CMakeFiles/sat.dir/satcircle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sat.dir/satcircle.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\libsat\satcircle.cpp > CMakeFiles\sat.dir\satcircle.cpp.i

CMakeFiles/sat.dir/satcircle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sat.dir/satcircle.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\libsat\satcircle.cpp -o CMakeFiles\sat.dir\satcircle.cpp.s

CMakeFiles/sat.dir/satcircle.cpp.obj.requires:

.PHONY : CMakeFiles/sat.dir/satcircle.cpp.obj.requires

CMakeFiles/sat.dir/satcircle.cpp.obj.provides: CMakeFiles/sat.dir/satcircle.cpp.obj.requires
	$(MAKE) -f CMakeFiles\sat.dir\build.make CMakeFiles/sat.dir/satcircle.cpp.obj.provides.build
.PHONY : CMakeFiles/sat.dir/satcircle.cpp.obj.provides

CMakeFiles/sat.dir/satcircle.cpp.obj.provides.build: CMakeFiles/sat.dir/satcircle.cpp.obj


CMakeFiles/sat.dir/satpolygon.cpp.obj: CMakeFiles/sat.dir/flags.make
CMakeFiles/sat.dir/satpolygon.cpp.obj: satpolygon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\libsat\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sat.dir/satpolygon.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sat.dir\satpolygon.cpp.obj -c D:\git\libsat\satpolygon.cpp

CMakeFiles/sat.dir/satpolygon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sat.dir/satpolygon.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\libsat\satpolygon.cpp > CMakeFiles\sat.dir\satpolygon.cpp.i

CMakeFiles/sat.dir/satpolygon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sat.dir/satpolygon.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\libsat\satpolygon.cpp -o CMakeFiles\sat.dir\satpolygon.cpp.s

CMakeFiles/sat.dir/satpolygon.cpp.obj.requires:

.PHONY : CMakeFiles/sat.dir/satpolygon.cpp.obj.requires

CMakeFiles/sat.dir/satpolygon.cpp.obj.provides: CMakeFiles/sat.dir/satpolygon.cpp.obj.requires
	$(MAKE) -f CMakeFiles\sat.dir\build.make CMakeFiles/sat.dir/satpolygon.cpp.obj.provides.build
.PHONY : CMakeFiles/sat.dir/satpolygon.cpp.obj.provides

CMakeFiles/sat.dir/satpolygon.cpp.obj.provides.build: CMakeFiles/sat.dir/satpolygon.cpp.obj


CMakeFiles/sat.dir/satbox.cpp.obj: CMakeFiles/sat.dir/flags.make
CMakeFiles/sat.dir/satbox.cpp.obj: satbox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\git\libsat\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sat.dir/satbox.cpp.obj"
	C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\sat.dir\satbox.cpp.obj -c D:\git\libsat\satbox.cpp

CMakeFiles/sat.dir/satbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sat.dir/satbox.cpp.i"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\git\libsat\satbox.cpp > CMakeFiles\sat.dir\satbox.cpp.i

CMakeFiles/sat.dir/satbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sat.dir/satbox.cpp.s"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\git\libsat\satbox.cpp -o CMakeFiles\sat.dir\satbox.cpp.s

CMakeFiles/sat.dir/satbox.cpp.obj.requires:

.PHONY : CMakeFiles/sat.dir/satbox.cpp.obj.requires

CMakeFiles/sat.dir/satbox.cpp.obj.provides: CMakeFiles/sat.dir/satbox.cpp.obj.requires
	$(MAKE) -f CMakeFiles\sat.dir\build.make CMakeFiles/sat.dir/satbox.cpp.obj.provides.build
.PHONY : CMakeFiles/sat.dir/satbox.cpp.obj.provides

CMakeFiles/sat.dir/satbox.cpp.obj.provides.build: CMakeFiles/sat.dir/satbox.cpp.obj


# Object files for target sat
sat_OBJECTS = \
"CMakeFiles/sat.dir/libsat.cpp.obj" \
"CMakeFiles/sat.dir/satvector.cpp.obj" \
"CMakeFiles/sat.dir/satcircle.cpp.obj" \
"CMakeFiles/sat.dir/satpolygon.cpp.obj" \
"CMakeFiles/sat.dir/satbox.cpp.obj"

# External object files for target sat
sat_EXTERNAL_OBJECTS =

libsat.a: CMakeFiles/sat.dir/libsat.cpp.obj
libsat.a: CMakeFiles/sat.dir/satvector.cpp.obj
libsat.a: CMakeFiles/sat.dir/satcircle.cpp.obj
libsat.a: CMakeFiles/sat.dir/satpolygon.cpp.obj
libsat.a: CMakeFiles/sat.dir/satbox.cpp.obj
libsat.a: CMakeFiles/sat.dir/build.make
libsat.a: CMakeFiles/sat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\git\libsat\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libsat.a"
	$(CMAKE_COMMAND) -P CMakeFiles\sat.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sat.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sat.dir/build: libsat.a

.PHONY : CMakeFiles/sat.dir/build

CMakeFiles/sat.dir/requires: CMakeFiles/sat.dir/libsat.cpp.obj.requires
CMakeFiles/sat.dir/requires: CMakeFiles/sat.dir/satvector.cpp.obj.requires
CMakeFiles/sat.dir/requires: CMakeFiles/sat.dir/satcircle.cpp.obj.requires
CMakeFiles/sat.dir/requires: CMakeFiles/sat.dir/satpolygon.cpp.obj.requires
CMakeFiles/sat.dir/requires: CMakeFiles/sat.dir/satbox.cpp.obj.requires

.PHONY : CMakeFiles/sat.dir/requires

CMakeFiles/sat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sat.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sat.dir/clean

CMakeFiles/sat.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\git\libsat D:\git\libsat D:\git\libsat D:\git\libsat D:\git\libsat\CMakeFiles\sat.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sat.dir/depend

