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
    //static std::string compress(std::string &input, const std::uint64_t &lookahead_buf, const std::uint64_t &search_buf);
    static std::vector<lz77_word> compressForBytes(char* &input, const std::int64_t &tab_size, const std::int64_t &lookahead_buf, const std::int64_t &search_buf);
    //static std::string decompress(const lz77_word *tab, const std::uint64_t &tab_size, const std::uint64_t &lookahead_buf, const std::uint64_t &output_buf);
    static std::vector<char> decompressForBytes(const std::vector<lz77_word> &tab, const std::int64_t &lookahead_buf, const std::int64_t &output_buf);

};


#endif //LZ77COMPRESSOR_LZ77_H
