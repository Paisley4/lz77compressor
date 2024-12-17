//
// Created by Krzysztof on 21.11.2024.
//

#include "lz77.h"
#include "char_utils.h"

#include "testing.h"

/*std::string lz77::compress(std::string &input, const __int64 &lookahead_buf, const __int64 &search_buf) {

    std::string result;

    const __int64 window_size = lookahead_buf + search_buf;

    char *window = new char[window_size + 1];

    // Always has to be next element that will be iterated.
    __int64 input_position;

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

    lz77_word lz77Word{};

    // Iterating all possible words.
    while (input_position - search_buf < input.size()){
        //std::cout << input_position-search_buf << "/" << input.size() << std::endl;

        lz77Word = char_utils::find_longest_string(window, lookahead_buf, search_buf);

        // If there is no matching code, we should set key as a first key of search buffer.
        if(lz77Word.C == 0)
            lz77Word.S = window[lookahead_buf];

        result += std::to_string(lz77Word.P);
        result += " ";
        result += std::to_string(lz77Word.C);
        result += " ";
        result += std::to_string((int) lz77Word.S);
        result += "\n";

        char_utils::slide_array(window, window_size, input, input_position, std::min(lz77Word.C + 1, search_buf));
    }

    delete []window;

    return result;
}*/

/*std::vector<lz77_word> lz77::compressForBytes(char* &input, const __int64 &tab_size, const __int64 &lookahead_buf, const __int64 &search_buf) {

    std::vector<lz77_word> result;

    const __int64 window_size = lookahead_buf + search_buf;

    char *window = new char[window_size + 1];

    // Always has to be next element that will be iterated.
    __int64 input_position;

    // Copying input to our buffer.
    // At start, we are filling only search buffer.
    // Checking if size of string is bigger than size of mix input buffer and history buffer
    for(input_position = 0; input_position < search_buf; input_position++){
        // In case buffer is bigger than input string, we should stop copying chars to buffer
        if(input_position >= tab_size)
            break;
        window[input_position+lookahead_buf] = input[input_position];
    }

    // Initialize search buffer.
    for(__int64 i = 0; i < lookahead_buf; i++){
        window[i] = input[0];
    }

    input_position = search_buf;

    lz77_word lz77Word{};

    // Iterating all possible words.
    while (input_position - search_buf < tab_size){
        std::cout << input_position-search_buf << "/" << tab_size << std::endl;

        lz77Word = char_utils::find_longest_string(window, lookahead_buf, search_buf);

        // If there is no matching code, we should set key as a first key of search buffer.
        if(lz77Word.C == 0)
            lz77Word.S = window[lookahead_buf];

        result.push_back(lz77Word);

        char_utils::slide_array(window, window_size, input, input_position, lz77Word.C + 1);
    }

    delete []window;

    return result;
}*/

std::vector<lz77_word> lz77::compressForBytes(char* &input, const __int64 &tab_size, const __int64 &lookahead_buf, const __int64 &search_buf) {

    std::vector<lz77_word> result;

    // Always has to be next element that will be iterated.
    __int64 window_position = -lookahead_buf;

    lz77_word lz77Word{};

    // Iterating all possible words.
    while (window_position < tab_size - lookahead_buf){
        std::cout << window_position << "/" << tab_size << std::endl;

        lz77Word = char_utils::find_longest_string(input, tab_size, window_position, lookahead_buf, search_buf);

        // If there is no matching code, we should set key as a first key of search buffer.
        if(lz77Word.C == 0)
            lz77Word.S = input[lookahead_buf + window_position];

        result.push_back(lz77Word);

        //char_utils::slide_array(window, window_size, input, input_position, lz77Word.C + 1);
        std::cout << " O : " << lz77Word.C + 1 << std::endl;
        window_position += lz77Word.C + 1;
    }

    return result;
}

/*std::string lz77::decompress(const lz77_word *tab, const __int64 &tab_size, const __int64 &lookahead_buf, const __int64 &output_buf) {

    std::string result;

    const __int64 window_size = lookahead_buf + output_buf;
    __int64 window_position = lookahead_buf;

    char *window = new char[window_size + 1];

    // Initializing lookahead buffer with starting character.
    for(__int64 i = 0; i < lookahead_buf; i++)
        window[i] = tab[0].S;

    // Initializing search buffer with spaces.
    for(__int64 i = 0; i < window_size - lookahead_buf; i++)
        window[i + lookahead_buf] = ' ';

    for(__int64 i = 0; i < tab_size; i++){
        window_position += tab[i].C;
        char_utils::copy_array(window, window_size, lookahead_buf, tab[i].P, tab[i].C);
        if(window_position < lookahead_buf + output_buf)
            window[window_position] = tab[i].S;
        for(__int64 d = 0; d < tab[i].C + 1; d++){
            if(window[d + lookahead_buf] == 0)
                continue;
            result += (char) window[d + lookahead_buf];
        }
        char_utils::slide_array(window, window_size, std::min(tab[i].C + 1, output_buf));
        window_position -= tab[i].C;

    }

    delete []window;

    return result;

}*/

/*std::vector<char> lz77::decompressForBytes(const std::vector<lz77_word> &tab, const __int64 &lookahead_buf, const __int64 &output_buf) {

    std::vector<char> result;

    const __int64 window_size = lookahead_buf + output_buf;
    __int64 window_position = lookahead_buf;

    char *window = new char[window_size + 1];

    // Initializing lookahead buffer with starting character.
    for(__int64 i = 0; i < lookahead_buf; i++)
        window[i] = tab[0].S;

    // Initializing search buffer with spaces.
    for(__int64 i = 0; i < window_size - lookahead_buf; i++)
        window[i + lookahead_buf] = ' ';

    for(__int64 i = 0; i < tab.size() - 1; i++){
        window_position += tab[i].C;
        char_utils::copy_array(window, window_size, lookahead_buf, tab[i].P, tab[i].C);
        if(window_position < lookahead_buf + output_buf)
            window[window_position] = tab[i].S;
        for(__int64 d = 0; d < tab[i].C + 1; d++){
            if((char) window[d + lookahead_buf] == 0)
                continue;
            result.push_back(window[d + lookahead_buf]);
        }
        //testing::printVec(result);
        // std::cout << result.size() << std::endl;
        //testing::printTab(window, window_size, lookahead_buf);
        char_utils::slide_array(window, window_size, std::min(tab[i].C + 1, output_buf));
        //std::cout << "test" << std::endl;
        window_position -= tab[i].C;
    }

    delete []window;

    return result;

}*/

std::vector<char> lz77::decompressForBytes(const std::vector<lz77_word> &tab, const __int64 &lookahead_buf, const __int64 &output_buf) {

    std::vector<char> result;

    __int64 window_position = -lookahead_buf;

    for(__int64 i = 0; i < tab.size() - 1; i++){
        char_utils::copy_array(result, window_position, lookahead_buf, tab[i].P, tab[i].C);
        result.push_back(tab[i].S);
        //testing::printVec(result);
        // std::cout << result.size() << std::endl;
        //testing::printTab(window, window_size, lookahead_buf);
        //char_utils::slide_array(window, window_size, std::min(tab[i].C + 1, output_buf));
        //std::cout << "test" << std::endl;
        //window_position -= tab[i].C;
        window_position += tab[i].C;
    }

    return result;

}