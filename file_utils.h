//
// Created by Krzysztof on 11.12.2024.
//

#ifndef LZ77COMPRESSOR_FILE_UTILS_H
#define LZ77COMPRESSOR_FILE_UTILS_H

#include <iostream>
#include <fstream>
#include <vector>

class file_utils {
public:
    static std::string readStringFromFile(const std::string &filename);
    static std::vector<std::string> readStringsFromFile(const std::string &filename);
};


#endif //LZ77COMPRESSOR_FILE_UTILS_H
