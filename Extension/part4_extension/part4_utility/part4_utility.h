//
// Created by ll7818 on 2019/6/11.
//

#ifndef ARM11_31_PART4_UTILITY_H
#define ARM11_31_PART4_UTILITY_H


#include <stdbool.h>



void strrev(char *s);

bool isValid(int d);

bool isBin(char *number);

int bin2dec(char *bin);

int operate_arith(int n1, int n2, char *operator);

char *int_to_str(int n);

char *dec2bin(int n);

#endif //ARM11_31_PART4_UTILITY_H

