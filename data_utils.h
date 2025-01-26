//
// Created by Krzysztof on 21/01/2025.
//

#ifndef DATA_UTILS_H
#define DATA_UTILS_H
#include <cstdint>


class data_utils {

public:
    /**
     * @brief Returns bit size of number.
     *
     * @param number Number that bit size we want to get.
     * @return Bit size of number.
     */
    static int16_t getNumberBitSize(int64_t number);
};



#endif //DATA_UTILS_H
