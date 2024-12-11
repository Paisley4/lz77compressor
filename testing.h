//
// Created by Krzysztof on 21.11.2024.
//

#ifndef LZ77COMPRESSOR_TESTING_H
#define LZ77COMPRESSOR_TESTING_H

#include <iostream>

#include <fstream>
#include <sstream>
#include <vector>
#include "lz77_word.h"

class testing {
public:
    static std::string generateRandomString(long long int size);
    static void info(std::string& text, const std::string& filename);
    static void printTab(char *tab, __int64 size){
        for(__int64 i = 0; i < size; i++){
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    }
    static void printTab(char *tab, __int64 size, __int64 split){
        for(__int64 i = 0; i < size; i++){
            if(i == split)
                std::cout << "| ";
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    }
    static __int64 copyStringToTab(char *&tab, std::string &str){
        tab = new char[str.length()];
        for(__int64 i = 0; i < str.length(); i++)
            tab[i] = str[i];
        return str.length();
    }
    static void writeToFile(std::string& text, const std::string& filename){
        std::fstream file;
        file.open(filename, std::ios::app);

        file << text;

        file.close();
    }
    static __int64 readWords(lz77_word*& tab, const std::string& filename){
        std::ifstream file(filename);

        std::string line;

        std::vector<lz77_word> words;

        lz77_word word{};

        int P, C, S;

        while (std::getline(file, line)){
            std::istringstream iss(line);
            if(iss >> P >> C >> S){
                word.P = P;
                word.C = C;
                word.S = char(S);
                words.push_back(word);
            }
        }

        tab = new lz77_word[words.size()];

        for(__int64 i = 0; i < words.size(); i++){
            tab[i] = words[i];
        }

        file.close();

        return words.size();

    }
};


#endif //LZ77COMPRESSOR_TESTING_H
