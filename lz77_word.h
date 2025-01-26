//
// Created by Krzysztof on 26.11.2024.
//

#ifndef LZ77COMPRESSOR_LZ77_WORD_H
#define LZ77COMPRESSOR_LZ77_WORD_H

#include <iostream>
#include <cstdint>

class lz77_word {

public:
    /// @brief On which position from start of window there is matching string.
    std::uint16_t P;
    /// @brief How long matching string is.
    std::uint16_t C;
    /// @brief Next byte after matching string.
    char S;

};


#endif //LZ77COMPRESSOR_LZ77_WORD_H
