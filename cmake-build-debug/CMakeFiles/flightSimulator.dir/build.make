# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/nisan/Desktop/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nisan/Desktop/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nisan/CLionProjects/flightSimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nisan/CLionProjects/flightSimulator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/flightSimulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/flightSimulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/flightSimulator.dir/flags.make

CMakeFiles/flightSimulator.dir/main.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/flightSimulator.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/main.cpp.o -c /home/nisan/CLionProjects/flightSimulator/main.cpp

CMakeFiles/flightSimulator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/main.cpp > CMakeFiles/flightSimulator.dir/main.cpp.i

CMakeFiles/flightSimulator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/main.cpp -o CMakeFiles/flightSimulator.dir/main.cpp.s

CMakeFiles/flightSimulator.dir/expressions/BinaryExpression.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/expressions/BinaryExpression.cpp.o: ../expressions/BinaryExpression.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/flightSimulator.dir/expressions/BinaryExpression.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/expressions/BinaryExpression.cpp.o -c /home/nisan/CLionProjects/flightSimulator/expressions/BinaryExpression.cpp

CMakeFiles/flightSimulator.dir/expressions/BinaryExpression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/expressions/BinaryExpression.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/expressions/BinaryExpression.cpp > CMakeFiles/flightSimulator.dir/expressions/BinaryExpression.cpp.i

CMakeFiles/flightSimulator.dir/expressions/BinaryExpression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/expressions/BinaryExpression.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/expressions/BinaryExpression.cpp -o CMakeFiles/flightSimulator.dir/expressions/BinaryExpression.cpp.s

CMakeFiles/flightSimulator.dir/expressions/Number.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/expressions/Number.cpp.o: ../expressions/Number.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/flightSimulator.dir/expressions/Number.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/expressions/Number.cpp.o -c /home/nisan/CLionProjects/flightSimulator/expressions/Number.cpp

CMakeFiles/flightSimulator.dir/expressions/Number.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/expressions/Number.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/expressions/Number.cpp > CMakeFiles/flightSimulator.dir/expressions/Number.cpp.i

CMakeFiles/flightSimulator.dir/expressions/Number.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/expressions/Number.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/expressions/Number.cpp -o CMakeFiles/flightSimulator.dir/expressions/Number.cpp.s

CMakeFiles/flightSimulator.dir/expressions/Plus.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/expressions/Plus.cpp.o: ../expressions/Plus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/flightSimulator.dir/expressions/Plus.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/expressions/Plus.cpp.o -c /home/nisan/CLionProjects/flightSimulator/expressions/Plus.cpp

CMakeFiles/flightSimulator.dir/expressions/Plus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/expressions/Plus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/expressions/Plus.cpp > CMakeFiles/flightSimulator.dir/expressions/Plus.cpp.i

CMakeFiles/flightSimulator.dir/expressions/Plus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/expressions/Plus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/expressions/Plus.cpp -o CMakeFiles/flightSimulator.dir/expressions/Plus.cpp.s

CMakeFiles/flightSimulator.dir/expressions/Minus.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/expressions/Minus.cpp.o: ../expressions/Minus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/flightSimulator.dir/expressions/Minus.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/expressions/Minus.cpp.o -c /home/nisan/CLionProjects/flightSimulator/expressions/Minus.cpp

CMakeFiles/flightSimulator.dir/expressions/Minus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/expressions/Minus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/expressions/Minus.cpp > CMakeFiles/flightSimulator.dir/expressions/Minus.cpp.i

CMakeFiles/flightSimulator.dir/expressions/Minus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/expressions/Minus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/expressions/Minus.cpp -o CMakeFiles/flightSimulator.dir/expressions/Minus.cpp.s

CMakeFiles/flightSimulator.dir/expressions/Mult.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/expressions/Mult.cpp.o: ../expressions/Mult.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/flightSimulator.dir/expressions/Mult.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/expressions/Mult.cpp.o -c /home/nisan/CLionProjects/flightSimulator/expressions/Mult.cpp

CMakeFiles/flightSimulator.dir/expressions/Mult.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/expressions/Mult.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/expressions/Mult.cpp > CMakeFiles/flightSimulator.dir/expressions/Mult.cpp.i

CMakeFiles/flightSimulator.dir/expressions/Mult.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/expressions/Mult.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/expressions/Mult.cpp -o CMakeFiles/flightSimulator.dir/expressions/Mult.cpp.s

CMakeFiles/flightSimulator.dir/expressions/Div.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/expressions/Div.cpp.o: ../expressions/Div.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/flightSimulator.dir/expressions/Div.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/expressions/Div.cpp.o -c /home/nisan/CLionProjects/flightSimulator/expressions/Div.cpp

CMakeFiles/flightSimulator.dir/expressions/Div.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/expressions/Div.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/expressions/Div.cpp > CMakeFiles/flightSimulator.dir/expressions/Div.cpp.i

CMakeFiles/flightSimulator.dir/expressions/Div.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/expressions/Div.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/expressions/Div.cpp -o CMakeFiles/flightSimulator.dir/expressions/Div.cpp.s

CMakeFiles/flightSimulator.dir/expressions/MathExpCalc.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/expressions/MathExpCalc.cpp.o: ../expressions/MathExpCalc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/flightSimulator.dir/expressions/MathExpCalc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/expressions/MathExpCalc.cpp.o -c /home/nisan/CLionProjects/flightSimulator/expressions/MathExpCalc.cpp

CMakeFiles/flightSimulator.dir/expressions/MathExpCalc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/expressions/MathExpCalc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/expressions/MathExpCalc.cpp > CMakeFiles/flightSimulator.dir/expressions/MathExpCalc.cpp.i

CMakeFiles/flightSimulator.dir/expressions/MathExpCalc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/expressions/MathExpCalc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/expressions/MathExpCalc.cpp -o CMakeFiles/flightSimulator.dir/expressions/MathExpCalc.cpp.s

CMakeFiles/flightSimulator.dir/commands/OpenServerCommand.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/OpenServerCommand.cpp.o: ../commands/OpenServerCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/flightSimulator.dir/commands/OpenServerCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/OpenServerCommand.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/OpenServerCommand.cpp

CMakeFiles/flightSimulator.dir/commands/OpenServerCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/OpenServerCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/OpenServerCommand.cpp > CMakeFiles/flightSimulator.dir/commands/OpenServerCommand.cpp.i

CMakeFiles/flightSimulator.dir/commands/OpenServerCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/OpenServerCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/OpenServerCommand.cpp -o CMakeFiles/flightSimulator.dir/commands/OpenServerCommand.cpp.s

CMakeFiles/flightSimulator.dir/commands/Lexer.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/Lexer.cpp.o: ../commands/Lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/flightSimulator.dir/commands/Lexer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/Lexer.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/Lexer.cpp

CMakeFiles/flightSimulator.dir/commands/Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/Lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/Lexer.cpp > CMakeFiles/flightSimulator.dir/commands/Lexer.cpp.i

CMakeFiles/flightSimulator.dir/commands/Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/Lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/Lexer.cpp -o CMakeFiles/flightSimulator.dir/commands/Lexer.cpp.s

CMakeFiles/flightSimulator.dir/commands/LoopCommand.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/LoopCommand.cpp.o: ../commands/LoopCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/flightSimulator.dir/commands/LoopCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/LoopCommand.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/LoopCommand.cpp

CMakeFiles/flightSimulator.dir/commands/LoopCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/LoopCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/LoopCommand.cpp > CMakeFiles/flightSimulator.dir/commands/LoopCommand.cpp.i

CMakeFiles/flightSimulator.dir/commands/LoopCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/LoopCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/LoopCommand.cpp -o CMakeFiles/flightSimulator.dir/commands/LoopCommand.cpp.s

CMakeFiles/flightSimulator.dir/commands/DefineVarCommand.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/DefineVarCommand.cpp.o: ../commands/DefineVarCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/flightSimulator.dir/commands/DefineVarCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/DefineVarCommand.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/DefineVarCommand.cpp

CMakeFiles/flightSimulator.dir/commands/DefineVarCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/DefineVarCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/DefineVarCommand.cpp > CMakeFiles/flightSimulator.dir/commands/DefineVarCommand.cpp.i

CMakeFiles/flightSimulator.dir/commands/DefineVarCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/DefineVarCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/DefineVarCommand.cpp -o CMakeFiles/flightSimulator.dir/commands/DefineVarCommand.cpp.s

CMakeFiles/flightSimulator.dir/commands/ConnectCommand.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/ConnectCommand.cpp.o: ../commands/ConnectCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/flightSimulator.dir/commands/ConnectCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/ConnectCommand.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/ConnectCommand.cpp

CMakeFiles/flightSimulator.dir/commands/ConnectCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/ConnectCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/ConnectCommand.cpp > CMakeFiles/flightSimulator.dir/commands/ConnectCommand.cpp.i

CMakeFiles/flightSimulator.dir/commands/ConnectCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/ConnectCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/ConnectCommand.cpp -o CMakeFiles/flightSimulator.dir/commands/ConnectCommand.cpp.s

CMakeFiles/flightSimulator.dir/commands/ConditionParser.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/ConditionParser.cpp.o: ../commands/ConditionParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/flightSimulator.dir/commands/ConditionParser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/ConditionParser.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/ConditionParser.cpp

CMakeFiles/flightSimulator.dir/commands/ConditionParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/ConditionParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/ConditionParser.cpp > CMakeFiles/flightSimulator.dir/commands/ConditionParser.cpp.i

CMakeFiles/flightSimulator.dir/commands/ConditionParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/ConditionParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/ConditionParser.cpp -o CMakeFiles/flightSimulator.dir/commands/ConditionParser.cpp.s

CMakeFiles/flightSimulator.dir/commands/IfCommand.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/IfCommand.cpp.o: ../commands/IfCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/flightSimulator.dir/commands/IfCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/IfCommand.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/IfCommand.cpp

CMakeFiles/flightSimulator.dir/commands/IfCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/IfCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/IfCommand.cpp > CMakeFiles/flightSimulator.dir/commands/IfCommand.cpp.i

CMakeFiles/flightSimulator.dir/commands/IfCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/IfCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/IfCommand.cpp -o CMakeFiles/flightSimulator.dir/commands/IfCommand.cpp.s

CMakeFiles/flightSimulator.dir/commands/PrintCommand.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/PrintCommand.cpp.o: ../commands/PrintCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/flightSimulator.dir/commands/PrintCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/PrintCommand.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/PrintCommand.cpp

CMakeFiles/flightSimulator.dir/commands/PrintCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/PrintCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/PrintCommand.cpp > CMakeFiles/flightSimulator.dir/commands/PrintCommand.cpp.i

CMakeFiles/flightSimulator.dir/commands/PrintCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/PrintCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/PrintCommand.cpp -o CMakeFiles/flightSimulator.dir/commands/PrintCommand.cpp.s

CMakeFiles/flightSimulator.dir/commands/SleepCommand.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/SleepCommand.cpp.o: ../commands/SleepCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/flightSimulator.dir/commands/SleepCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/SleepCommand.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/SleepCommand.cpp

CMakeFiles/flightSimulator.dir/commands/SleepCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/SleepCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/SleepCommand.cpp > CMakeFiles/flightSimulator.dir/commands/SleepCommand.cpp.i

CMakeFiles/flightSimulator.dir/commands/SleepCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/SleepCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/SleepCommand.cpp -o CMakeFiles/flightSimulator.dir/commands/SleepCommand.cpp.s

CMakeFiles/flightSimulator.dir/commands/AssertionCommand.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/AssertionCommand.cpp.o: ../commands/AssertionCommand.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/flightSimulator.dir/commands/AssertionCommand.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/AssertionCommand.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/AssertionCommand.cpp

CMakeFiles/flightSimulator.dir/commands/AssertionCommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/AssertionCommand.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/AssertionCommand.cpp > CMakeFiles/flightSimulator.dir/commands/AssertionCommand.cpp.i

CMakeFiles/flightSimulator.dir/commands/AssertionCommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/AssertionCommand.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/AssertionCommand.cpp -o CMakeFiles/flightSimulator.dir/commands/AssertionCommand.cpp.s

CMakeFiles/flightSimulator.dir/commands/CommandExpression.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/CommandExpression.cpp.o: ../commands/CommandExpression.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/flightSimulator.dir/commands/CommandExpression.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/CommandExpression.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/CommandExpression.cpp

CMakeFiles/flightSimulator.dir/commands/CommandExpression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/CommandExpression.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/CommandExpression.cpp > CMakeFiles/flightSimulator.dir/commands/CommandExpression.cpp.i

CMakeFiles/flightSimulator.dir/commands/CommandExpression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/CommandExpression.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/CommandExpression.cpp -o CMakeFiles/flightSimulator.dir/commands/CommandExpression.cpp.s

CMakeFiles/flightSimulator.dir/commands/commandsFactory.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/commandsFactory.cpp.o: ../commands/commandsFactory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/flightSimulator.dir/commands/commandsFactory.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/commandsFactory.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/commandsFactory.cpp

CMakeFiles/flightSimulator.dir/commands/commandsFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/commandsFactory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/commandsFactory.cpp > CMakeFiles/flightSimulator.dir/commands/commandsFactory.cpp.i

CMakeFiles/flightSimulator.dir/commands/commandsFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/commandsFactory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/commandsFactory.cpp -o CMakeFiles/flightSimulator.dir/commands/commandsFactory.cpp.s

CMakeFiles/flightSimulator.dir/commands/ReadFromServer.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/commands/ReadFromServer.cpp.o: ../commands/ReadFromServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object CMakeFiles/flightSimulator.dir/commands/ReadFromServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/commands/ReadFromServer.cpp.o -c /home/nisan/CLionProjects/flightSimulator/commands/ReadFromServer.cpp

CMakeFiles/flightSimulator.dir/commands/ReadFromServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/commands/ReadFromServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/commands/ReadFromServer.cpp > CMakeFiles/flightSimulator.dir/commands/ReadFromServer.cpp.i

CMakeFiles/flightSimulator.dir/commands/ReadFromServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/commands/ReadFromServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/commands/ReadFromServer.cpp -o CMakeFiles/flightSimulator.dir/commands/ReadFromServer.cpp.s

CMakeFiles/flightSimulator.dir/GenFunc.cpp.o: CMakeFiles/flightSimulator.dir/flags.make
CMakeFiles/flightSimulator.dir/GenFunc.cpp.o: ../GenFunc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Building CXX object CMakeFiles/flightSimulator.dir/GenFunc.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flightSimulator.dir/GenFunc.cpp.o -c /home/nisan/CLionProjects/flightSimulator/GenFunc.cpp

CMakeFiles/flightSimulator.dir/GenFunc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flightSimulator.dir/GenFunc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nisan/CLionProjects/flightSimulator/GenFunc.cpp > CMakeFiles/flightSimulator.dir/GenFunc.cpp.i

CMakeFiles/flightSimulator.dir/GenFunc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flightSimulator.dir/GenFunc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nisan/CLionProjects/flightSimulator/GenFunc.cpp -o CMakeFiles/flightSimulator.dir/GenFunc.cpp.s

# Object files for target flightSimulator
flightSimulator_OBJECTS = \
"CMakeFiles/flightSimulator.dir/main.cpp.o" \
"CMakeFiles/flightSimulator.dir/expressions/BinaryExpression.cpp.o" \
"CMakeFiles/flightSimulator.dir/expressions/Number.cpp.o" \
"CMakeFiles/flightSimulator.dir/expressions/Plus.cpp.o" \
"CMakeFiles/flightSimulator.dir/expressions/Minus.cpp.o" \
"CMakeFiles/flightSimulator.dir/expressions/Mult.cpp.o" \
"CMakeFiles/flightSimulator.dir/expressions/Div.cpp.o" \
"CMakeFiles/flightSimulator.dir/expressions/MathExpCalc.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/OpenServerCommand.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/Lexer.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/LoopCommand.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/DefineVarCommand.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/ConnectCommand.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/ConditionParser.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/IfCommand.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/PrintCommand.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/SleepCommand.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/AssertionCommand.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/CommandExpression.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/commandsFactory.cpp.o" \
"CMakeFiles/flightSimulator.dir/commands/ReadFromServer.cpp.o" \
"CMakeFiles/flightSimulator.dir/GenFunc.cpp.o"

# External object files for target flightSimulator
flightSimulator_EXTERNAL_OBJECTS =

flightSimulator: CMakeFiles/flightSimulator.dir/main.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/expressions/BinaryExpression.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/expressions/Number.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/expressions/Plus.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/expressions/Minus.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/expressions/Mult.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/expressions/Div.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/expressions/MathExpCalc.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/OpenServerCommand.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/Lexer.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/LoopCommand.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/DefineVarCommand.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/ConnectCommand.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/ConditionParser.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/IfCommand.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/PrintCommand.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/SleepCommand.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/AssertionCommand.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/CommandExpression.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/commandsFactory.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/commands/ReadFromServer.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/GenFunc.cpp.o
flightSimulator: CMakeFiles/flightSimulator.dir/build.make
flightSimulator: CMakeFiles/flightSimulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_23) "Linking CXX executable flightSimulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flightSimulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/flightSimulator.dir/build: flightSimulator

.PHONY : CMakeFiles/flightSimulator.dir/build

CMakeFiles/flightSimulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/flightSimulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/flightSimulator.dir/clean

CMakeFiles/flightSimulator.dir/depend:
	cd /home/nisan/CLionProjects/flightSimulator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nisan/CLionProjects/flightSimulator /home/nisan/CLionProjects/flightSimulator /home/nisan/CLionProjects/flightSimulator/cmake-build-debug /home/nisan/CLionProjects/flightSimulator/cmake-build-debug /home/nisan/CLionProjects/flightSimulator/cmake-build-debug/CMakeFiles/flightSimulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/flightSimulator.dir/depend

