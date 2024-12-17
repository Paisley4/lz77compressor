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
    static std::string readStringFromFile(const std::string &filename);
    static void readBytesFromFile(const std::string &filename, char*& tab, __int64& tab_size);
    static std::vector<std::string> readStringsFromFile(const std::string &filename);
    static __int64 readCompressedWordsFromFile(lz77_word*& tab, const std::string &filename);
    static std::vector<lz77_word> readCompressedByteWordsFromFile(const std::string &filename);
    static void writeCompressedByteWordsToFile(const std::string &filename, std::vector<lz77_word> words);
    static void writeToFile(std::string& text, const std::string& filename);
    static void writeBytesToFile(const std::string &filename, std::vector<char> data);
    static void writeBytesToFile(const std::string &filename, char* &tab, __int64& tab_size);
};


#endif //LZ77COMPRESSOR_FILE_UTILS_H
