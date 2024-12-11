//
// Created by Krzysztof on 21.11.2024.
//

#ifndef LZ77COMPRESSOR_CHAR_UTILS_H
#define LZ77COMPRESSOR_CHAR_UTILS_H

#include <iostream>

#include "lz77_word.h"

class char_utils {

public:
    static void slide_array(char *tab, __int64 tab_size, std::string input, __int64 &position);
    static void slide_array(char *tab, __int64 tab_size, const std::string& input, __int64 &position, __int64 n);
    static void slide_array(char *tab, __int64 tab_size);
    static void slide_array(char *tab, __int64 tab_size, __int64 n);
    static lz77_word find_longest_string(char *tab, __int64 tab_size, __int64 lookahead_buf, __int64 search_buf);
    static bool contain_word(const char *tab, __int64 lookahead_buf, __int64 begin, __int64 end, lz77_word &word);
    static void copy_array(char *tab, __int64 tab_size, __int64 lookahead_buf, __int64 begin, __int64 n);

};


#endif //LZ77COMPRESSOR_CHAR_UTILS_H
