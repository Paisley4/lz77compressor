//
// Created by Katarzyna Szczepaniak on 21/01/2025.
//

#include "data_utils.h"

int16_t data_utils::getNumberBitSize(int64_t number) {
    int16_t size = 0;

    if (number == 0) {
        return 0;
    }

    while (number != 0) {
        number = number >> 1;
        size++;
    }

    return size;
}
