cmake_minimum_required(VERSION 3.13)
project(fsServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(fsServer main.cpp ServerSide.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h CacheManager.h FileCacheManager.cpp FileCacheManager.h)