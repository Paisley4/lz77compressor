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
    /**
     * @brief Compresses input using LZ77 algorithm.
     *
     * @param input Array of input file bytes.
     * @param tab_size Size of input array.
     * @param lookahead_buf Length of look-ahead buffer.
     * @param search_buf Length of search buffer.
     * @return Vector of compressed input.
     */
    static std::vector<lz77_word> compressForBytes(char* input, std::int64_t tab_size, std::int64_t lookahead_buf, std::int64_t search_buf);
    /**
     * @brief Decompresses vector of LZ77 words using LZ77 algorithm.
     *
     * @param tab Vector of compressed words.
     * @param lookahead_buf Length of look-ahead buffer.
     * @return Vector of decompressed bytes.
     */
    static std::vector<char> decompressForBytes(const std::vector<lz77_word> &tab, std::int64_t lookahead_buf);

};


#endif //LZ77COMPRESSOR_LZ77_H
