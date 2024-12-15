//
// Created by Krzysztof on 11.12.2024.
//

#include <sstream>
#include "file_utils.h"

std::string file_utils::readStringFromFile(const std::string &filename) {
    std::ifstream file(filename);

    // Reading whole file to buffer.
    std::stringstream buffer;
    buffer << file.rdbuf();

    file.close();

    return buffer.str();
}

void file_utils::readBytesFromFile(const std::string &filename, char*& tab, __int64& tab_size){
    std::ifstream file(filename, std::ios::ios_base::in | std::ios::ios_base::binary);

    file.seekg(0, std::ios::end);
    tab_size = file.tellg();
    file.seekg(0, std::ios::beg);

    tab = new char[tab_size];

    file.read(tab, tab_size);

    std::vector<char> test;

    file.close();
}

std::vector<std::string> file_utils::readStringsFromFile(const std::string &filename) {
    std::ifstream file(filename);

    std::string line;
    std::vector<std::string> result;

    // Reading file line by line and inserting strings to vector
    while (std::getline(file, line))
        result.push_back(line);

    file.close();

    return result;
}

__int64 file_utils::readCompressedWordsFromFile(lz77_word*& tab, const std::string &filename){
    std::vector<std::string> lines = file_utils::readStringsFromFile(filename);

    std::vector<lz77_word> words;

    lz77_word word{};

    int P, C, S;

    // Take every line and split it into P, C and S.
    for(const std::string& line : lines){
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

    return (__int64) words.size();
}

void file_utils::writeToFile(std::string& text, const std::string& filename){
    std::ofstream file;
    file.open(filename, std::ios::app);

    file << text;

    file.close();
}

void file_utils::writeBytesToFile(const std::string &filename, char *&tab, __int64 &tab_size) {
    std::fstream file;
    file.open(filename, std::ios::ios_base::binary | std::ios::ios_base::out);

    file.write(tab, tab_size);

    file.close();
}

