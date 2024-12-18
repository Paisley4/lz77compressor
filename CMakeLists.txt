cmake_minimum_required(VERSION 3.29)
project(lz77compressor)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(lz77compressor main.cpp
        lz77.cpp
        lz77.h
        char_utils.cpp
        char_utils.h
        lz77_word.cpp
        lz77_word.h
        file_utils.cpp
        file_utils.h
        logger.cpp
        logger.h
)
