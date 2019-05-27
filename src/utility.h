//
// Created by Rini Banerjee on 2019-05-25.
//

#include <stdlib.h>

#ifndef SRC_UTILITY_H
#define SRC_UTILITY_H

uint32_t get_n_bits(uint32_t b, int start_pos, int number_of_bits);
uint32_t change_bit(uint32_t b, int pos, int val);
uint32_t rotateRightOne(uint32_t b);
uint32_t rotateRight(uint32_t b, int n);
struct stateOfMachine* createNewState();

#endif //SRC_UTILITY_H
