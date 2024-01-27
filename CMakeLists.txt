cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled main.cpp message/message.cpp message/message.h messageQueue/messageQueue.cpp messageQueue/messageQueue.h functions/functions.cpp functions/functions.h)
