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
    //static std::string compress(std::string &input, const __int64 &lookahead_buf, const __int64 &search_buf);
    // Test for bytes
    static std::vector<lz77_word> compressForBytes(char* &input, const __int64 &tab_size, const __int64 &lookahead_buf, const __int64 &search_buf);
    //static std::string decompress(const lz77_word *tab, const __int64 &tab_size, const __int64 &lookahead_buf, const __int64 &output_buf);
    // Also test for bytes
    static std::vector<char> decompressForBytes(const std::vector<lz77_word> &tab, const __int64 &lookahead_buf, const __int64 &output_buf);

};


#endif //LZ77COMPRESSOR_LZ77_H
