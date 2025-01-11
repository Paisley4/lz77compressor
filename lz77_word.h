//
// Created by Krzysztof on 26.11.2024.
//

#ifndef LZ77COMPRESSOR_LZ77_WORD_H
#define LZ77COMPRESSOR_LZ77_WORD_H

#include <iostream>
#include <cstdint>

class lz77_word {

public:
    std::uint16_t P, C;
    char S;

};


#endif //LZ77COMPRESSOR_LZ77_WORD_H
