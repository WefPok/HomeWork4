# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\nikman\CLionProjects\HomeWork3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\nikman\CLionProjects\HomeWork3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\HomeWork3.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\HomeWork3.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\HomeWork3.dir\flags.make

CMakeFiles\HomeWork3.dir\main.cpp.obj: CMakeFiles\HomeWork3.dir\flags.make
CMakeFiles\HomeWork3.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nikman\CLionProjects\HomeWork3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HomeWork3.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\HomeWork3.dir\main.cpp.obj /FdCMakeFiles\HomeWork3.dir\ /FS -c C:\Users\nikman\CLionProjects\HomeWork3\main.cpp
<<

CMakeFiles\HomeWork3.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HomeWork3.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\HomeWork3.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\nikman\CLionProjects\HomeWork3\main.cpp
<<

CMakeFiles\HomeWork3.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HomeWork3.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\HomeWork3.dir\main.cpp.s /c C:\Users\nikman\CLionProjects\HomeWork3\main.cpp
<<

# Object files for target HomeWork3
HomeWork3_OBJECTS = \
"CMakeFiles\HomeWork3.dir\main.cpp.obj"

# External object files for target HomeWork3
HomeWork3_EXTERNAL_OBJECTS =

HomeWork3.exe: CMakeFiles\HomeWork3.dir\main.cpp.obj
HomeWork3.exe: CMakeFiles\HomeWork3.dir\build.make
HomeWork3.exe: CMakeFiles\HomeWork3.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\nikman\CLionProjects\HomeWork3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HomeWork3.exe"
	"C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\HomeWork3.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100171~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100171~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\HomeWork3.dir\objects1.rsp @<<
 /out:HomeWork3.exe /implib:HomeWork3.lib /pdb:C:\Users\nikman\CLionProjects\HomeWork3\cmake-build-debug\HomeWork3.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\HomeWork3.dir\build: HomeWork3.exe

.PHONY : CMakeFiles\HomeWork3.dir\build

CMakeFiles\HomeWork3.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HomeWork3.dir\cmake_clean.cmake
.PHONY : CMakeFiles\HomeWork3.dir\clean

CMakeFiles\HomeWork3.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\nikman\CLionProjects\HomeWork3 C:\Users\nikman\CLionProjects\HomeWork3 C:\Users\nikman\CLionProjects\HomeWork3\cmake-build-debug C:\Users\nikman\CLionProjects\HomeWork3\cmake-build-debug C:\Users\nikman\CLionProjects\HomeWork3\cmake-build-debug\CMakeFiles\HomeWork3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\HomeWork3.dir\depend
