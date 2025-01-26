cmake_minimum_required(VERSION 3.30)
project(lz77compressor)

if(WIN32)
    set(CMAKE_CXX_FLAGS  "-static")
endif ()
set(CMAKE_CXX_STANDARD 23)

add_executable(lz77compressor main.cpp
        lz77.cpp
        lz77.h
        char_utils.cpp
        char_utils.h
        lz77_word.h
        file_utils.cpp
        file_utils.h
        logger.cpp
        logger.h
        data_utils.cpp
        data_utils.h
)
