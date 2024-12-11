//
// Created by Krzysztof on 21.11.2024.
//

#include "lz77.h"
#include "char_utils.h"

#include "testing.h"

std::string lz77::compress(std::string input, __int64 lookahead_buf, __int64 search_buf) {

    testing::info(input, "logfile.txt");

    std::string result;

    __int64 window_size = lookahead_buf + search_buf;

    char *window = new char[window_size];

    // Always has to be next element that will be iterated.
    __int64 input_position;

    __int64 max_buffer_input = ((__int64) input.size() < (lookahead_buf + search_buf) ? (__int64) input.size() : lookahead_buf + search_buf);

    // Copying input to our buffer.
    // At start, we are filling only search buffer.
    // Checking if size of string is bigger than size of mix input buffer and history buffer
    for(input_position = 0; input_position < search_buf; input_position++){
        // In case buffer is bigger than input string, we should stop copying chars to buffer
        if(input_position >= input.size())
            break;
        window[input_position+lookahead_buf] = input[input_position];
    }

    // Initialize search buffer.
    for(__int64 i = 0; i < lookahead_buf; i++){
        window[i] = input[0];
    }

    input_position = search_buf;
    //testing::printTab(window, window_size);

    lz77_word lz77Word{};

    // Iterating all possible words.
    while (input_position - search_buf < input.size()){
        lz77Word = char_utils::find_longest_string(window, window_size, lookahead_buf, search_buf);

        // If there is no matching code, we should set key as a first key of search buffer.
        if(lz77Word.C == 0)
            lz77Word.S = window[lookahead_buf];

        //std::string test;
        result += std::to_string(lz77Word.P);
        result += " ";
        result += std::to_string(lz77Word.C);
        result += " ";
        result += std::to_string((int) lz77Word.S);
        result += "\n";
        //testing::info(test, "logfile.txt");

        char_utils::slide_array(window, window_size, input, input_position, lz77Word.C + 1);
        //testing::printTab(window, window_size, lookahead_buf);
    }


    /*std::cout << "Before: ";
    for(__int64 i = 0; i < window_size; i++){
        std::cout << window[i] << " ";
    }

    char_utils::slide_array(window, window_size, input, input_position);

    std::cout << std::endl << "Slided: ";
    for(__int64 i = 0; i < window_size; i++){
        std::cout << window[i] << " ";
    }*/

    delete []window;

    return result;
}

std::string lz77::decompress(lz77_word *tab, __int64 tab_size, __int64 lookahead_buf, __int64 output_buf) {

    std::string result;

    __int64 window_size = lookahead_buf + output_buf;
    __int64 window_position = lookahead_buf;

    char *window = new char[window_size];

    // Initializing lookahead buffer with starting character.
    for(__int64 i = 0; i < lookahead_buf; i++){
        window[i] = tab[0].S;
    }

    for(__int64 i = 0; i < window_size - lookahead_buf; i++)
        window[i + lookahead_buf] = ' ';

    //testing::printTab(window, window_size, lookahead_buf);

    for(__int64 i = 0; i < tab_size; i++){
        window_position += tab[i].C;
        char_utils::copy_array(window, window_size, lookahead_buf, tab[i].P, tab[i].C);
        window[window_position] = tab[i].S;
        //testing::printTab(window, window_size, lookahead_buf);
        for(__int64 d = 0; d < tab[i].C + 1; d++){
            result += (char) window[d + lookahead_buf];
        }
        char_utils::slide_array(window, window_size, tab[i].C + 1);
        window_position -= tab[i].C;
    }

    delete []window;

    return result;

}
