//
// Created by Rini Banerjee on 2019-05-25.
//

#include <stdlib.h>

#ifndef SRC_UTILITY_H
#define SRC_UTILITY_H

uint32_t get_n_bits(uint32_t b, int start_pos, int number_of_bits);
void change_bit(uint32_t b, int pos, int val);
uint32_t rotateRight(uint32_t b, int n);
struct stateOfMachine* createNewState();
uint32_t shiftLeft(uint32_t b, int n);
uint32_t shiftRight(uint32_t b, int n);
uint32_t arShiftRight(uint32_t b, int n);
uint32_t shiftRegister(uint32_t b, uint32_t amount, uint32_t shiftType);
uint32_t makeASRmask(int shiftAmount);
bool checkCondition(struct stateOfMachine state, Cond condition);


#endif //SRC_UTILITY_H
