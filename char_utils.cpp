//
// Created by Krzysztof on 21.11.2024.
//

#include "char_utils.h"

/*void char_utils::slide_array(char *tab, const __int64 &tab_size, std::string input, __int64 &position) {

    for(__int64 i = 1; i < tab_size; i++){
        tab[i - 1] = tab[i];
    }

    if(position >= input.size()){
        tab[tab_size-1] = ' ';
    }else{
        tab[tab_size-1] = input[position];
    }

    position++;

}

void char_utils::slide_array(char *tab, const __int64 &tab_size, const std::string& input, __int64 &position, const __int64 &n) {

    for(__int64 c = 0; c < n; c++){
        char_utils::slide_array(tab, tab_size, input, position);
    }

}*/

void char_utils::slide_array(char *tab, const __int64 &tab_size) {

    for(__int64 i = 1; i < tab_size; i++){
        tab[i - 1] = tab[i];
    }

    tab[tab_size-1] = ' ';

}

void char_utils::slide_array(char *tab, const __int64 &tab_size, const __int64 &n) {

    for(__int64 c = 0; c < n; c++){
        char_utils::slide_array(tab, tab_size);
    }

}

/*lz77_word char_utils::find_longest_string(char *tab, const __int64 &lookahead_buf, const __int64 &search_buf) {

    lz77_word lz77Word{0, 0, tab[lookahead_buf+1]};

    __int64 index = lookahead_buf + search_buf - 1;

    do {

        if(char_utils::contain_word(tab, lookahead_buf, lookahead_buf, index, lz77Word)){
            lz77Word.S = tab[lz77Word.C + lookahead_buf];
            break;
        }

        index--;
    } while (index > lookahead_buf);

    return lz77Word;

}*/

lz77_word char_utils::find_longest_string(char *tab, const __int64 &tab_size, const __int64 &window_position, const __int64 &lookahead_buf, const __int64 &search_buf) {

    lz77_word lz77Word{0, 0, tab[window_position+lookahead_buf]};

    __int64 index = std::min(window_position + lookahead_buf + search_buf, tab_size) - 1;

    do {
        //std::cout << index << std::endl;
        //std::cout << "CO " << index << " " << window_position + lookahead_buf + 1 << std::endl;
        if(char_utils::contain_word(tab, lookahead_buf, window_position, index, lz77Word)){
            //std::cout << lookahead_buf << " " << window_position << " " << index << std::endl;
            lz77Word.S = tab[window_position + lz77Word.C + lookahead_buf];
            //std::cout << "DO " << index << " " << lz77Word.C + 1 << std::endl;
            break;
        }
        index--;
    }while (index > window_position + lookahead_buf);

    return lz77Word;

}

// Checks if string contains specified substring.
bool char_utils::contain_word(const char *tab, const __int64 &lookahead_buf, const __int64 &window_position, const __int64 &end, lz77_word &word) {


    for(__int64 lookahead_index = 0; lookahead_index < lookahead_buf; lookahead_index++){

        if(lookahead_buf - lookahead_index < end - lookahead_buf + window_position){
            //std::cout << "Zwrocono dla " << word.S << std::endl;
            return false;
        }

        bool isOk = true;

        for(__int64 search_index = 0; search_index < end - lookahead_buf - window_position + 1; search_index++){

            //std::cout << tab[std::max((__int64) 0, lookahead_index + window_position)] << " != " << tab[search_index + window_position + lookahead_buf] << std::endl;

            if(tab[std::max((__int64) 0, lookahead_index + window_position + search_index)] != tab[search_index + window_position + lookahead_buf]){
                isOk = false;
                break;
            }

            //lookahead_index++;

        }

        if(isOk){
            word.P = lookahead_index;
            word.C = end - window_position - lookahead_buf + 1;
            //std::cout << end << " " << word.C << " " << word.S << std::endl;
            return true;
        }

    }

    return false;

}

// KMP algorithm
/*bool char_utils::contain_word(const char *tab, const __int64 &lookahead_buf, const __int64 &begin, const __int64 &end, lz77_word &word) {

    // Creating prefix array.
    std::vector<__int64> pref;
    __int64 j = 0;
    __int64 m = end - begin + 1;
    pref.resize(m, 0);
    for(__int64 k = 1; k < m; k++){
        while (j > 0 && tab[begin + j] != tab[begin + k])
            j = pref[j - 1];

        if(tab[begin + j] == tab[begin + k])
            j++;

        pref[k] = j;
    }

    j = 0;
    for(__int64 i = 0; i < lookahead_buf; i++){
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

void char_utils::copy_array(char *tab, const __int64 &window_position, const __int64 &lookahead_buf, const __int64 &begin, const __int64 &n) {

    for(__int64 i = 0; i < n; i++){
        //std::cout << lookahead_buf + i << " " << begin + i << std::endl;
        tab[std::max(lookahead_buf + i + window_position, (__int64) 0)] = tab[begin + i + window_position];
    }

}

void char_utils::copy_array(std::vector<char> &tab, const __int64 &window_position, const __int64 &lookahead_buf, const __int64 &begin, const __int64 &n) {

    //std::cout << n << std::endl;

    for(__int64 i = 0; i < n; i++){
        //std::cout << window_position << std::endl;
        //std::cout << "Pobieram z: " << std::max(window_position + i, (__int64) 0) << " " << tab[std::max(window_position + i, (__int64) 0)] << std::endl;
        tab.push_back(tab[std::max(window_position + begin + i, (__int64) 0)]);
    }

}
