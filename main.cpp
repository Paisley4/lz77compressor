#include <iostream>
#include "lz77.h"

#include "testing.h"
#include "char_utils.h"

int main() {

    //std::cout << lz77::compress("")

    //std::string testString = testing::generateRandomString(100);
    //std::string testString = "Miałem robić mapę wczoraj, nie chciało mi się bo sił nie miałem karnąłem się na 193 i tyle, a dziś chciałem i znów plany się pokrzyżowały XD";

    //std::cout << testString << std::endl << std::endl;

    //std::string result = lz77::compress(testString, 15, 15);

    //testing::writeToFile(result, "compressed.txt");

    /*char *tab = {"cdabecdxyz"};

    lz77_word word{};
    for(int i = 9; i > 5; i--){
        if(char_utils::contain_word(tab, 5, 5, i, word)){
            std::cout << "(" << word.P + 1 << "," << word.C << "," << (int) word.S << ")" << std::endl;
        }

    }*/

    /*std::string test = "abcdefghijklnbhdoeps";
    char *tab;
    __int64 tab_size = testing::copyStringToTab(tab, test);
    __int64 lookahead_buf = tab_size/2;

    char_utils::copy_array(tab, tab_size, lookahead_buf, 4, 3);

    testing::printTab(tab, tab_size);*/

    /*lz77_word *tab;
    __int64 tab_size = testing::readWords(tab, "compressed.txt");

    std::string s;

    s = lz77::decompress(tab, tab_size, 15, 15);

    std::cout << s;*/

    std::cout << "NIGŁA";

    return 0;
}
