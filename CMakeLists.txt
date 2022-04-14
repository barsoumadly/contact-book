cmake_minimum_required(VERSION 3.21)
project(ContactBook)

set(CMAKE_CXX_STANDARD 14)

add_executable(ContactBook main.cpp Contact.cpp Contact.h Contact_Book.cpp Contact_Book.h contact_utils/Display.cpp contact_utils/Display.h contact_utils/Search.cpp contact_utils/Search.h contact_utils/Delete.cpp contact_utils/Delete.h contact_utils/Add.cpp contact_utils/Add.h contact_utils/common_libraries.h)
