//
// Created by Krzysztof on 11.12.2024.
//

#include "file_utils.h"

void file_utils::readBytesFromFile(const std::string &filename, char*& tab, std::int64_t& tab_size){
    std::ifstream file(filename, std::ios::ios_base::in | std::ios::ios_base::binary);

    file.seekg(0, std::ios::end);
    tab_size = file.tellg();
    file.seekg(0, std::ios::beg);

    tab = new char[tab_size];

    file.read(tab, tab_size);

    std::vector<char> test;

    file.close();
}

std::vector<lz77_word> file_utils::readCompressedByteWordsFromFile(const std::string &filename){
    std::fstream file(filename, std::ios::binary | std::ios::in);

    std::vector<lz77_word> words;

    lz77_word word{};

    char *buff = new char[2];

    while(!file.eof()){
        file.read(buff, 2);
        memcpy(&word.P, buff, 2);
        file.read(buff, 2);
        memcpy(&word.C, buff, 2);
        file.read(buff, 1);
        memcpy(&word.S, buff, 1);
        words.push_back(word);
    }

    delete []buff;

    return words;
}

void file_utils::writeBytesToFile(const std::string &filename, std::vector<char> data) {
    std::fstream file;
    file.open(filename, std::ios::ios_base::binary | std::ios::ios_base::out);

    char *tab = new char[data.size()];

    for(std::uint64_t i = 0; i < data.size(); i++)
        tab[i] = data[i];

    file.write(tab, data.size());

    file.close();

    delete []tab;
}

void file_utils::writeCompressedByteWordsToFile(const std::string &filename, std::vector<lz77_word> words) {
    std::fstream file(filename, std::ios::binary | std::ios::out);

    char *buff = new char[2];

    for(const lz77_word word : words){

        memcpy(buff, &word.P, 2);
        file.write(buff, 2);
        memcpy(buff, &word.C, 2);
        file.write(buff, 2);
        memcpy(buff, &word.S, 1);
        file.write(buff, 1);
    }

    file.close();

    delete []buff;
}
