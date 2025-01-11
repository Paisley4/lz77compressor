//
// Created by Krzysztof on 11.12.2024.
//

#ifndef LZ77COMPRESSOR_FILE_UTILS_H
#define LZ77COMPRESSOR_FILE_UTILS_H

#include <iostream>
#include <fstream>
#include <vector>

#include "lz77_word.h"

class file_utils {
public:
    static void readBytesFromFile(const std::string &filename, char*& tab, std::int64_t& tab_size);
    static std::vector<lz77_word> readCompressedByteWordsFromFile(const std::string &filename);
    static void writeCompressedByteWordsToFile(const std::string &filename, std::vector<lz77_word> words);
    static void writeBytesToFile(const std::string &filename, std::vector<char> data);
};


#endif //LZ77COMPRESSOR_FILE_UTILS_H
