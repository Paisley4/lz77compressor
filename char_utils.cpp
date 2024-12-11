//
// Created by Krzysztof on 21.11.2024.
//

#include "char_utils.h"

void char_utils::slide_array(char *tab, __int64 tab_size, std::string input, __int64 &position) {

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

void char_utils::slide_array(char *tab, __int64 tab_size, const std::string& input, __int64 &position, __int64 n) {

    for(__int64 c = 0; c < n; c++){
        char_utils::slide_array(tab, tab_size, input, position);
    }

}

void char_utils::slide_array(char *tab, __int64 tab_size) {

    for(__int64 i = 1; i < tab_size; i++){
        tab[i - 1] = tab[i];
    }

    tab[tab_size-1] = ' ';

}

void char_utils::slide_array(char *tab, __int64 tab_size, __int64 n) {

    for(__int64 c = 0; c < n; c++){
        char_utils::slide_array(tab, tab_size);
    }

}

lz77_word char_utils::find_longest_string(char *tab, __int64 tab_size, __int64 lookahead_buf, __int64 search_buf) {

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

}

// Checks if string contains specified substring.
bool char_utils::contain_word(const char *tab, __int64 lookahead_buf, __int64 begin, __int64 end, lz77_word &word) {

    //std::cout << "NOWA" << std::endl;

    for(__int64 lookahead_index = 0; lookahead_index < lookahead_buf; lookahead_index++){

        if(lookahead_buf - lookahead_index < end - begin + 1)
            return false;

        bool isOk = true;

        for(__int64 search_index = 0; search_index < end - begin + 1; search_index++){

            if(tab[search_index + lookahead_index] != tab[search_index + begin]){

                //std::cout << "Break " << tab[search_index + lookahead_index] << " =/= " << tab[search_index + begin] << std::endl;

                isOk = false;
                break;
            }else{
                //std::cout << "Git " << tab[search_index + lookahead_index] << " == " << tab[search_index + begin] << std::endl;
            }

        }

        if(isOk){
            word.P = lookahead_index;
            word.C = end - begin + 1;
            return true;
        }

    }

    return false;

}

void char_utils::copy_array(char *tab, __int64 tab_size, __int64 lookahead_buf, __int64 begin, __int64 n) {

    //std::cout << begin << " " << n << std::endl;

    for(__int64 i = 0; i < n; i++){
        tab[tab_size - lookahead_buf + i] = tab[begin + i];
    }

}
