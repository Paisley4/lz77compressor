//
// Created by Krzysztof on 21.11.2024.
//

#include "char_utils.h"

lz77_word char_utils::find_longest_string(char* &tab, const std::uint64_t &tab_size, const std::uint64_t &window_position, const std::uint64_t &lookahead_buf, const std::uint64_t &search_buf) {

    lz77_word lz77Word{0, 0, tab[window_position+lookahead_buf]};

    std::uint64_t index = std::min(window_position + lookahead_buf + search_buf, tab_size) - 1;

    do {
        if(char_utils::contain_word(tab, lookahead_buf, window_position, index, lz77Word)){
            lz77Word.S = tab[window_position + lz77Word.C + lookahead_buf];
            break;
        }
        index--;
    }while (index > window_position + lookahead_buf);

    return lz77Word;

}

// Checks if string contains specified substring.
bool char_utils::contain_word(char* &tab, const std::uint64_t &lookahead_buf, const std::uint64_t &window_position, const std::uint64_t &end, lz77_word &word) {

    for(std::uint64_t lookahead_index = 0; lookahead_index < lookahead_buf; lookahead_index++){

        if(lookahead_buf - lookahead_index < end - lookahead_buf + window_position)
            return false;

        bool isOk = true;

        for(std::uint64_t search_index = 0; search_index < end - lookahead_buf - window_position + 1; search_index++){

            if(tab[std::max((std::uint64_t) 0, lookahead_index + window_position + search_index)] != tab[search_index + window_position + lookahead_buf]){
                isOk = false;
                break;
            }

        }

        if(isOk){
            word.P = lookahead_index;
            word.C = end - window_position - lookahead_buf + 1;
            return true;
        }

    }

    return false;

}

// KMP algorithm
/*bool char_utils::contain_word(const char *tab, const std::uint64_t &lookahead_buf, const std::uint64_t &begin, const std::uint64_t &end, lz77_word &word) {

    // Creating prefix array.
    std::vector<std::uint64_t> pref;
    std::uint64_t j = 0;
    std::uint64_t m = end - begin + 1;
    pref.resize(m, 0);
    for(std::uint64_t k = 1; k < m; k++){
        while (j > 0 && tab[begin + j] != tab[begin + k])
            j = pref[j - 1];

        if(tab[begin + j] == tab[begin + k])
            j++;

        pref[k] = j;
    }

    j = 0;
    for(std::uint64_t i = 0; i < lookahead_buf; i++){
        while(j > 0 && tab[begin + j] != tab[i])
            j = pref[j - 1];

        if(tab[begin + j] == tab[i])
            j++;

        if(j == m){
            word.P = i - m + 1;
            word.C = end - begin + 1;
            return true;
        }
    }

    return false;

}*/

void char_utils::copy_array(std::vector<char> &tab, const std::uint64_t &window_position, const std::uint64_t &begin, const std::uint64_t &n) {

    for(std::uint64_t i = 0; i < n; i++)
        tab.push_back(tab[std::max(window_position + begin + i, (std::uint64_t) 0)]);

}
