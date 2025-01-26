//
// Created by Krzysztof on 21.11.2024.
//

#include "lz77.h"
#include "char_utils.h"

/**
 * @brief Compresses input using LZ77 algorithm.
 *
 * @param input Array of input file bytes.
 * @param tab_size Size of input array.
 * @param lookahead_buf Length of look-ahead buffer.
 * @param search_buf Length of search buffer.
 * @return Vector of compressed input.
 */
std::vector<lz77_word> lz77::compressForBytes(char* input, std::int64_t tab_size, std::int64_t lookahead_buf, std::int64_t search_buf) {

    std::vector<lz77_word> result;

    // Always has to be next element that will be iterated.
    std::int64_t window_position = -lookahead_buf;

    lz77_word lz77Word{};

    // Iterating all possible words.
    while (window_position < tab_size - lookahead_buf){
        lz77Word = char_utils::findLongestString(input, window_position, lookahead_buf, search_buf);

        // If there is no matching code, we should set key as a first key of search buffer.
        if(lz77Word.C == 0)
            lz77Word.S = input[lookahead_buf + window_position];

        result.push_back(lz77Word);

        window_position += lz77Word.C + 1;
    }

    return result;
}

/**
 * @brief Decompresses vector of LZ77 words using LZ77 algorithm.
 *
 * @param tab Vector of compressed words.
 * @param lookahead_buf Length of look-ahead buffer.
 * @return Vector of decompressed bytes.
 */
std::vector<char> lz77::decompressForBytes(const std::vector<lz77_word> &tab, std::int64_t lookahead_buf) {

    std::vector<char> result;

    int64_t window_position = -lookahead_buf;

    for(uint64_t i = 0; i < tab.size() - 1; i++){
        char_utils::copyArray(result, window_position, tab[i].P, tab[i].C);
        if (i+1 < tab.size() - 1)
            result.push_back(tab[i].S);
        window_position += tab[i].C + 1;
    }

    return result;

}