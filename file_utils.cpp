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

    return buffer.str();
}

std::vector<std::string> file_utils::readStringsFromFile(const std::string &filename) {
    std::ifstream file(filename);

    std::string line;
    std::vector<std::string> result;

    // Reading file line by line and inserting strings to vector
    while (std::getline(file, line))
        result.push_back(line);

    return result;
}

