//
// Created by Krzysztof on 11.12.2024.
//

#include "file_utils.h"

#include "data_utils.h"

void file_utils::readBytesFromFile(const std::string &filename, char*& tab, std::int64_t& tab_size){
    std::ifstream file(filename, std::ios::ios_base::in | std::ios::ios_base::binary);

    file.seekg(0, std::ios::end);
    tab_size = file.tellg();
    file.seekg(0, std::ios::beg);

    tab = new char[tab_size];

    file.read(tab, tab_size);

    file.close();
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

std::vector<lz77_word> file_utils::readCompressedWordsFromFile(const std::string &filename, uint16_t lookahead_buffer_size, uint16_t search_buffer_size) {
    std::fstream file(filename, std::ios::binary | std::ios::in);
    std::vector<lz77_word> words;

    int16_t lookaheadBitSize = data_utils::getNumberBitSize(lookahead_buffer_size-1), searchBitSize = data_utils::getNumberBitSize(search_buffer_size-1);

    lz77_word word{};
    int64_t buffer_size = 0;
    file.seekg(0, std::ios::end);
    buffer_size = file.tellg();
    file.seekg(0, std::ios::beg);

    char *buffer = new char[buffer_size];

    file.read(buffer, buffer_size);

    int8_t bitPosition = 0;
    int64_t bytePosition = 0;

    while ((buffer_size - bytePosition) * 8 - bitPosition >= 0) {
        word.P = 0;
        for (uint16_t i = 0; i < lookaheadBitSize; i++) {
            word.P = word.P << 1 | (buffer[bytePosition] >> (7 - bitPosition) & 1);
            bitPosition++;
            if (bitPosition >= 8) {
                bitPosition = 0;
                bytePosition++;
            }
        }
        word.C = 0;
        for (uint16_t i = 0; i < searchBitSize; i++) {
            word.C = word.C << 1 | (buffer[bytePosition] >> (7 - bitPosition) & 1);
            bitPosition++;
            if (bitPosition >= 8) {
                bitPosition = 0;
                bytePosition++;
            }
        }
        if (word.C > 0) {
            word.C++;
            word.P++;
        }
        word.S = 0;
        for (uint8_t i = 0; i < 8; i++) {
            word.S = word.S << 1 | (buffer[bytePosition] >> (7 - bitPosition) & 1);
            bitPosition++;
            if (bitPosition >= 8) {
                bitPosition = 0;
                bytePosition++;
            }
        }
        words.push_back(word);
    }

    delete []buffer;

    return words;
}

void file_utils::writeCompressedWordsToFile(const std::string &filename, const std::vector<lz77_word>& words, uint16_t lookahead_buffer_size, uint16_t search_buffer_size) {

    // Calculating size of bytes buffer
    int16_t lookaheadBitSize = data_utils::getNumberBitSize(lookahead_buffer_size-1), searchBitSize = data_utils::getNumberBitSize(search_buffer_size-1);

    uint64_t buffer_size = (lookaheadBitSize + searchBitSize + 8) * words.size() / 8;
    if (buffer_size * 8 != (lookaheadBitSize + searchBitSize + 8) * words.size()) {
        buffer_size++;
    }

    char *buffer = new char[buffer_size];

    char tempByte = 0;

    int8_t bitPosition = 0;
    int64_t bytePosition = 0;

    // Changing words to bytes
    for(lz77_word word : words) {
        if (word.C > 0) {
            word.C--;
            word.P--;
        }
        for (int16_t i = lookaheadBitSize - 1; i >= 0; i--) {
            tempByte = (tempByte << 1) | (word.P >> i & 1);
            bitPosition++;
            if (bitPosition >= 8) {
                bitPosition = 0;
                buffer[bytePosition] = tempByte;
                tempByte = 0;
                bytePosition++;
            }
        }
        for (int16_t i = searchBitSize - 1; i >= 0; i--) {
            tempByte = (tempByte << 1) | (word.C >> i & 1);
            bitPosition++;
            if (bitPosition >= 8) {
                bitPosition = 0;
                buffer[bytePosition] = tempByte;
                tempByte = 0;
                bytePosition++;
            }
        }
        for (int16_t i = 7; i >= 0; i--) {
            tempByte = (tempByte << 1) | (word.S >> i & 1);
            bitPosition++;
            if (bitPosition >= 8) {
                bitPosition = 0;
                buffer[bytePosition] = tempByte;
                tempByte = 0;
                bytePosition++;
            }
        }
    }

    // Completing byte
    while (bitPosition != 0) {
        tempByte = (tempByte << 1) | 0;
        bitPosition++;
        if (bitPosition >= 7) {
            buffer[bytePosition] = tempByte;
            bitPosition = 0;
        }
    }

    std::fstream file(filename, std::ios::binary | std::ios::out);

    file.write(buffer, buffer_size);

    file.close();

    delete []buffer;

}