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
    static lz77_word find_longest_string(char* &tab, const __int64 &tab_size, const __int64 &window_position, const __int64 &lookahead_buf, const __int64 &search_buf);
    static bool contain_word(char* &tab, const __int64 &lookahead_buf, const __int64 &window_position, const __int64 &end, lz77_word &word);
    static void copy_array(std::vector<char> &tab, const __int64 &window_position, const __int64 &begin, const __int64 &n);

};


#endif //LZ77COMPRESSOR_CHAR_UTILS_H
