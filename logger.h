//
// Created by Krzysztof on 11.12.2024.
//

#ifndef LZ77COMPRESSOR_LOGGER_H
#define LZ77COMPRESSOR_LOGGER_H

#include <iostream>
#include <fstream>

class logger {

public:
    /**
     * @brief Displays message and saves it to logfile.
     *
     * @param msg Information we want to display and save to logfile.
     */
    static void info(std::string msg);

};


#endif //LZ77COMPRESSOR_LOGGER_H
