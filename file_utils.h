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
    /**
     * @brief Reads bytes from file and writes it to array.
     *
     * @param filename Name of input file.
     * @param tab Array where bytes will be saved.
     * @param tab_size Variable where size of array will be saved.
     */
    static void readBytesFromFile(const std::string &filename, char*& tab, std::int64_t& tab_size);
    /**
     * @brief Writes vector of data to file.
     *
     * @param filename Name of output file.
     * @param data Vector of bytes.
     */
    static void writeBytesToFile(const std::string &filename, std::vector<char> data);
    /**
     * @brief Reads compressed LZ77 words from file.
     *
     * @param filename Name of input file.
     * @param lookahead_buffer_size Size of look-ahead buffer.
     * @param search_buffer_size Size of search buffer.
     * @return Vector of LZ77 compressed words.
     */
    static std::vector<lz77_word> readCompressedWordsFromFile(const std::string &filename, uint16_t lookahead_buffer_size, uint16_t search_buffer_size);
    /**
     * @brief Writes compressed LZ77 words to file.
     *
     * @param filename Name of input file.
     * @param words Vector of compressed LZ77 words.
     * @param lookahead_buffer_size Size of look-ahead buffer.
     * @param search_buffer_size Size of search buffer.
     */
    static void writeCompressedWordsToFile(const std::string &filename, const std::vector<lz77_word>& words, uint16_t lookahead_buffer_size, uint16_t search_buffer_size);
};


#endif //LZ77COMPRESSOR_FILE_UTILS_H
