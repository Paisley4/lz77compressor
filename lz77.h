//
// Created by Krzysztof on 21.11.2024.
//

#ifndef LZ77COMPRESSOR_LZ77_H
#define LZ77COMPRESSOR_LZ77_H

#include <iostream>

#include "lz77_word.h"

class lz77 {

public:
    static std::string compress(std::string &input, const __int64 &lookahead_buf, const __int64 &search_buf);
    static std::string decompress(const lz77_word *tab, const __int64 &tab_size, const __int64 &lookahead_buf, const __int64 &output_buf);

};


#endif //LZ77COMPRESSOR_LZ77_H
