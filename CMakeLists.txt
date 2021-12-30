cmake_minimum_required(VERSION 3.21)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

add_executable(Boost_Echo_Client include/connectionHandler.h src/connectionHandler.cpp src/echoClient.cpp src/encode.cpp include/encode.h)
