//
// Created by Krzysztof on 21.11.2024.
//

#include <chrono>

#include "lz77.h"
#include "char_utils.h"

std::vector<lz77_word> lz77::compressForBytes(char* &input, const __int64 &tab_size, const __int64 &lookahead_buf, const __int64 &search_buf) {

    std::vector<lz77_word> result;

    // Always has to be next element that will be iterated.
    __int64 window_position = -lookahead_buf;

    lz77_word lz77Word{};

    // Iterating all possible words.
    while (window_position < tab_size - lookahead_buf){
        lz77Word = char_utils::find_longest_string(input, tab_size, window_position, lookahead_buf, search_buf);

        // If there is no matching code, we should set key as a first key of search buffer.
        if(lz77Word.C == 0)
            lz77Word.S = input[lookahead_buf + window_position];

        result.push_back(lz77Word);

        window_position += lz77Word.C + 1;
    }

    return result;
}

std::vector<char> lz77::decompressForBytes(const std::vector<lz77_word> &tab, const __int64 &lookahead_buf, const __int64 &output_buf) {

    std::vector<char> result;

    __int64 window_position = -lookahead_buf;

    for(__int64 i = 0; i < tab.size() - 1; i++){
        char_utils::copy_array(result, window_position, lookahead_buf, tab[i].P, tab[i].C);
        result.push_back(tab[i].S);
        window_position += tab[i].C + 1;
    }

    return result;

}