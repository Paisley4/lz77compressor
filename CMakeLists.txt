cmake_minimum_required(VERSION 3.29)
project(lz77compressor)

set(CMAKE_CXX_STANDARD 23)

add_executable(lz77compressor main.cpp
        lz77.cpp
        lz77.h
        testing.cpp
        testing.h
        string_utils.cpp
        string_utils.h
        char_utils.cpp
        char_utils.h
        lz77_word.cpp
        lz77_word.h
)
