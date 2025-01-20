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
    static lz77_word findLongestString(char* &tab, std::uint64_t tab_size, std::int64_t window_position, std::uint64_t lookahead_buf, std::uint64_t search_buf);
    static void copyArray(std::vector<char> &tab, const std::int64_t &window_position, const std::uint64_t &begin, const std::uint64_t &n);

};


#endif //LZ77COMPRESSOR_CHAR_UTILS_H
