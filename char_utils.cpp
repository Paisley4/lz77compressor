//
// Created by Krzysztof on 21.11.2024.
//

#include "char_utils.h"

lz77_word char_utils::findLongestString(char* &tab, std::int64_t window_position, std::int64_t lookahead_buf, std::int64_t search_buf) {
    lz77_word word{0, 0, tab[window_position + lookahead_buf]};
    std::int64_t lookahead_index = 0, search_index = 0;

    lz77_word temp = word;
    while (lookahead_index < lookahead_buf && search_index < search_buf) {
        //std::cout << std::max(window_position + lookahead_index, (std::int64_t) 0) << " " << window_position + lookahead_buf + search_index << std::endl;
        if (tab[std::max(window_position + lookahead_index, (std::int64_t) 0)] == tab[window_position + lookahead_buf + search_index]) {
            temp.C++;
            temp.S = tab[window_position + lookahead_buf + search_index + 1];
            if (temp.C > word.C && temp.C > 1) {
                word = temp;
            }
            lookahead_index++;
            search_index++;
            continue;
        }
        // No matching letter, so reset values
        temp.P = lookahead_index + 1;
        temp.C = 0;
        temp.S = tab[std::max(window_position + lookahead_index, (std::int64_t) 0)];
        search_index = 0;
        lookahead_index++;
    }

    return word;
}

void char_utils::copyArray(std::vector<char> &tab, std::int64_t window_position, std::uint64_t begin, std::uint64_t n) {

    for(std::uint64_t i = 0; i < n; i++)
        tab.push_back(tab[std::max(window_position + begin + i, (std::uint64_t) 0)]);

}
