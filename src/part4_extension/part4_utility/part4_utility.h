//
// Created by ASUS on 2019/6/11.
//

#ifndef ARM11_31_PART4_UTILITY_H
#define ARM11_31_PART4_UTILITY_H


#include <stdbool.h>

int counter_main(void);
void counter(unsigned int x);
void rec2(int val, int count, int b);
void helper_rec(int val, int count);
int main();


bool isValid(int d);

bool isBin(char *number);

int bin2dec(char *bin);

//int bin2dec(char * binstr);
char *dec2bin(int n);

int operate_arith(int n1, int n2, char *operator);

char *int_to_str(int n);
//void convert_both_to_dec(int n1, int n2);
//int add(int n1, int n2);
//int subtract(int n1,int n2);
//int multiply(int n1,int n2);
//int divide(int n1,int n2);

#endif //ARM11_31_PART4_UTILITY_H

//typedef enum {
//    ADD = 1,
//    MUL = 2,
//    SUB = 3,
//    DIV = 4,
//} arith_type;
