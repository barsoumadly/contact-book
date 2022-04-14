cmake_minimum_required(VERSION 3.21)
project(ContactBook)

set(CMAKE_CXX_STANDARD 14)

add_executable(ContactBook main.cpp Contact.cpp Contact.h Contact_Book.cpp Contact_Book.h Display.cpp Display.h Search.cpp Search.h Delete.cpp Delete.h Add.cpp Add.h comman_libraries.h)
