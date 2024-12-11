//
// Created by Krzysztof on 21.11.2024.
//

#include "testing.h"
#include <chrono>
#include <random>

// Generates random string.
// For testing purpose only!
std::string testing::generateRandomString(__int64 size){
    std::string result;

    std::uniform_int_distribution<int> unif(97, 122);

    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());

    for(int i = 0; i < size; i++){
        result += (char) unif(generator);
    }

    return result;

}

void testing::info(std::string &text, const std::string &filename) {

    std::fstream file;
    file.open(filename, std::ios::app);

    file << text << std::endl;

    file.close();

}

