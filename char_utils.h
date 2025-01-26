//
// Created by Krzysztof on 21.11.2024.
//

#ifndef LZ77COMPRESSOR_CHAR_UTILS_H
#define LZ77COMPRESSOR_CHAR_UTILS_H

#include <iostream>
#include <vector>

#include "lz77_word.h"

class char_utils {

public:
    /**
     * @brief Finds longest string that repeats in look-ahead buffer and search buffer.
     *
     * @param tab Array with all bytes.
     * @param window_position Position of buffer window.
     * @param lookahead_buf Length of look-ahead buffer.
     * @param search_buf Length of search buffer.
     * @return Longest string in specified buffer window.
     */
    static lz77_word findLongestString(char* &tab, std::int64_t window_position, std::int64_t lookahead_buf, std::int64_t search_buf);

    /**
     * @brief Copies specified length of bytes at specified window position.
     *
     * @param tab Vector of bytes.
     * @param window_position Position of buffer window.
     * @param begin Position where string begins.
     * @param n Size of string.
     */
    static void copyArray(std::vector<char> &tab, std::int64_t window_position, std::uint64_t begin, std::uint64_t n);
};


#endif //LZ77COMPRESSOR_CHAR_UTILS_H
