//
// Created by ASUS on 2019/6/11.
//
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#include <bits/mathcalls.h>
#include "../part4_utility/part4_utility.h"
#include <math.h>

#define MAX_BINARY_DIGIT 10

//#include "math.h"

//#include "shine.h"


//check if a number(String) is in binary form
bool isBin(char *number) {
    int n;
    int length = strlen(number) - 1;
    for (int l = 0; l <= length; l++) {
        n = (number[l] - '0');
        if ((n > 1) || (n < 0)) {
            return 0;
        }
    }
    return 1;
}

//check if the decimal number is in range
bool isValid(int d) {
    return d >= 0 && d <= 7;
}


//convert binary number to decimal
int bin2dec(char *binstr) {
    int base = 1, dec = 0, rem;
    int bin = atoi(binstr);
    if (isBin(binstr))
        perror("\n ERROR! BINARY has only 1 and 0!\n");
    else {
        while (bin > 0) {
            rem = bin % 10;
            dec = dec + rem * base;
            bin = bin / 10;
            base = base * 2;
        }
    }
    return dec;
}



//convert decimal number to binary
char *dec2bin(int n) {
    int decimal=n, tempDecimal;
    char binary[MAX_BINARY_DIGIT];
    int index = 0;

    tempDecimal = decimal;

    while(tempDecimal!=0)
    {
        binary[index] = (tempDecimal % 2) + '0';

        tempDecimal /= 2;
        index++;
    }
    binary[index] = '\0';
    strrev(binary);
    return binary;
}


//convert an integer to a string
char *int_to_str(int n) {
    char str1[MAX_BINARY_DIGIT];
    sprintf(str1, "%d", n);
    return str1;
}


// +-*/ operation
int operate_arith(int n1, int n2, char *operator) {
    int result;
    char *strOfn1 = int_to_str(n1);
    char *strOfn2 = int_to_str(n2);
    if (isBin(strOfn1)) {
        n1 = bin2dec(strOfn1);
    }
    if (isBin(strOfn2)) {
        n2 = bin2dec(strOfn2);
    }

    if (!strcmp(operator, "add")) {
        result = n1 + n2;
    } else if (!strcmp(operator, "sub")) {
        result = n1 - n2;
    } else if (!strcmp(operator, "mul")) {
        result = n1 * n2;
    } else if (!strcmp(operator, "div")) {
        result = n1 / n2;
    } else {
        perror("Invalid arithmetic command on last line of the file.");
        EXIT_FAILURE;
    }
    if (isValid(result))
        return atoi(dec2bin(result));
    else {
        perror("Invalid result");
        EXIT_FAILURE;
    }

}
