//
// Created by Krzysztof on 21/01/2025.
//

#include "data_utils.h"

/**
 * @brief Returns bit size of number.
 *
 * @param number Number that bit size we want to get.
 * @return Bit size of number.
 */
int16_t data_utils::getNumberBitSize(int64_t number) {
    int16_t size = 0;

    if (number == 0) {
        return 1;
    }

    while (number != 0) {
        number = number >> 1;
        size++;
    }

    return size;
}
