//
// Created by Krzysztof on 21.11.2024.
//

#ifndef LZ77COMPRESSOR_LZ77_H
#define LZ77COMPRESSOR_LZ77_H

#include <iostream>
#include <vector>

#include "lz77_word.h"

class lz77 {

public:
    static std::vector<lz77_word> compressForBytes(char* input, std::int64_t tab_size, std::int64_t lookahead_buf, std::int64_t search_buf);
    static std::vector<char> decompressForBytes(const std::vector<lz77_word> &tab, std::int64_t lookahead_buf);

};


#endif //LZ77COMPRESSOR_LZ77_H
