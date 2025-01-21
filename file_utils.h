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
    static void writeBytesToFile(const std::string &filename, std::vector<char> data);
    static std::vector<lz77_word> readCompressedWordsFromFile(const std::string &filename, uint16_t lookahead_buffer_size, uint16_t search_buffer_size);
    static void writeCompressedWordsToFile(const std::string &filename, const std::vector<lz77_word>& words, uint16_t lookahead_buffer_size, uint16_t search_buffer_size);
};


#endif //LZ77COMPRESSOR_FILE_UTILS_H
