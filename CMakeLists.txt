cmake_minimum_required(VERSION 3.17)
project(Hash6)

set(CMAKE_CXX_STANDARD 11)

add_executable(Hash6 main.cpp hashtable.h hashtable.hpp passserver.h passserver.cpp base64.h base64.cpp)