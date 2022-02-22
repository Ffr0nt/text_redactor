cmake_minimum_required(VERSION 3.20)
project(text_redactor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(text_redactor
        main.cpp
        Document.cpp
        Document.h)
