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


//binary counter
void counter(unsigned int x) {
    char buffer[3];
    sprintf(buffer, "%u%u%u\n",

            //(x>>3)&0x1,

            (x >> 2) & 0x1,
            (x >> 1) & 0x1,
            x & 0x1);
    printf("%s", buffer)

    shine(buffer);
    printf("Now it's representing %s\n",buffer);
    if (x == 0x7U) return;
    else counter(x + 1);
}

//counter's main function
int counter_main(void) {
    printf("Mode 1, this is a 3-bit binary counter using raspberry pi and 3 LEDs\n");
    counter(0);
}

void rec2(int val, int count, int b) {
    if (count <= 1) {
        int i;
        for (i = b - 1; i >= 0; i--) {
            printf("%d", (val >> i) & 1);
        }
        printf("\n");
    } else {
        rec2(val * 2, count - 1, b);
        rec2(val * 2 + 1, count - 1, b);
    }
}

void helper_rec(int val, int count) {
    rec2(val, count, count);
}

int main() {
    helper_rec(0, 4);
    helper_rec(1, 4);
    return 0;
}


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
//int bin2dec(char *bin) {
//    int b, k, n;
//    int len, sum = 0;
//
//    len = strlen(bin) - 1;
//    for (k = 0; k <= len; k++) {
//        b = 1;
//        n = (bin[k] - '0'); // char to numeric value
//        if ((n > 1) || (n < 0)) {
//            puts("\n\n ERROR! BINARY has only 1 and 0!\n");
//            return (0);
//        }
//        b = b << (len - k);
//        // sum it up
//        sum = sum + n * b;
//        //printf("%d*%d + ",n,b);  // uncomment to show the way this works
//    }
//    return (sum);
//}

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

//char*dec2bin(int n){
//    int b=0;
//    b=n%2;
//}

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
