//
// Created by Krzysztof on 11.12.2024.
//

#include "logger.h"

/**
 * @brief Displays message and saves it to logfile.
 *
 * @param msg Information we want to display and save to logfile.
 */
void logger::info(std::string msg) {

    std::fstream file;
    file.open("logfile.txt", std::ios::app);

    file << "[INFO] " << msg << std::endl;
    std::cout << "[INFO] " << msg << std::endl;

    file.close();

}
