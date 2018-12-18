cmake_minimum_required(VERSION 3.12)
project(mainProj)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)
add_executable(mainProj main.cpp Command.h OpenServerCommand.cpp OpenServerCommand.h Lexer.cpp Lexer.h LoopCommand.cpp LoopCommand.h DefineVarCommand.cpp DefineVarCommand.h ConnectCommand.cpp ConnectCommand.h ConditionParser.cpp ConditionParser.h IfCommand.cpp IfCommand.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h AssertionCommand.cpp AssertionCommand.h CommandExpression.cpp CommandExpression.h Expression.h)