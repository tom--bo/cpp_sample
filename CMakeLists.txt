cmake_minimum_required(VERSION 3.17)
project(cpp_sample)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_sample main.cpp stack.h shared_memory.cpp shared_memory.h SimpleCounter.cpp SimpleCounter.h)
