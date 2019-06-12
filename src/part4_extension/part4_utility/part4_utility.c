//
// Created by ASUS on 2019/6/11.
//
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <bits/mathcalls.h>
#include "../part4_utility/part4_utility.h"
#include "math.h"
#include "shine.h"



void counter(unsigned int x)
{   char buffer[3];
    sprintf(buffer,"%u%u%u\n",

            //(x>>3)&0x1,
            (x>>2)&0x1,
            (x>>1)&0x1,
            x&0x1);
    printf("%s",buffer);
    shine(buffer);
    if(x==0x7U) return;
    else counter(x+1);

}

int counter_main(void)
{
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


bool isValid(int d) {
    return d >= 0 && d <= 7;
}


int bin2dec(char *bin) {
    int b, k, n;
    int len, sum = 0;

    len = strlen(bin) - 1;
    for (k = 0; k <= len; k++) {
        b = 1;
        n = (bin[k] - '0'); // char to numeric value
        if ((n > 1) || (n < 0)) {
            puts("\n\n ERROR! BINARY has only 1 and 0!\n");
            return (0);
        }
        b = b << (len - k);
        // sum it up
        sum = sum + n * b;
        //printf("%d*%d + ",n,b);  // uncomment to show the way this works
    }
    return (sum);
}

//int bin2dec(char *binstr) {
//    int dec = 0;
//    int len = strlen(binstr);
//    int i = 0;
//    while (i < len) {
//        dec = (dec << 1) + (binstr[i] - 0x30);
//        i++;
//    }
//    return dec;
//}

//char*dec2bin(int n){
//    int b=0;
//    b=n%2;
//}

char *dec2bin(int n) {
    int c, d, count;
    char *pointer;

    count = 0;
    pointer = (char *) malloc(32 + 1);

    if (pointer == NULL)
        exit(EXIT_FAILURE);

    for (c = 31; c >= 0; c--) {
        d = n >> c;

        if (d & 1)
            *(pointer + count) = 1 + '0';
        else
            *(pointer + count) = 0 + '0';

        count++;
    }
    *(pointer + count) = '\0';

    return pointer;
}

//void convert_both_to_dec(int n1, int n2) {
//    if (isBin(n1)) {
//        char str1[(int) ((ceil(log10(n1)) + 1) * sizeof(char))];
//        sprintf(str1, "%d", n1);
//        n1 = bin2dec(str1);
//    }
//    if (isBin(n2)) {
//        char str2[(int) ((ceil(log10(n2)) + 1) * sizeof(char))];
//        sprintf(str2, "%d", n2);
//        n2 = bin2dec(str2);
//    }
//}

char *int_to_str(int n) {
    char str1[(int) ((ceil(log10(n)) + 1) * sizeof(char))];
    sprintf(str1, "%d", n);
    return str1;
}

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

//int add(int n1, int n2) {
////    convert_both_to_dec(n1, n2);
//    if (isBin(n1)) {
//        char str1[(int) ((ceil(log10(n1)) + 1) * sizeof(char))];
//        sprintf(str1, "%d", n1);
//        n1 = bin2dec(str1);
//    }
//    if (isBin(n2)) {
//        char str2[(int) ((ceil(log10(n2)) + 1) * sizeof(char))];
//        sprintf(str2, "%d", n2);
//        n2 = bin2dec(str2);
//    }
//
//    if ((n1 + n2) >= 0 && (n1 + n2) <= 7) { return atoi(dec2bin((int) (n1 + n2))); }
//    else {
//        perror("Invalid Result");
//        EXIT_FAILURE;
//
//    }
//}
//
//int subtract(int n1, int n2) {
//    convert_both_to_dec(n1, n2);
//    if ((isValid(n1 * n2))) { return atoi(dec2bin((int) (n1 - n2))); }
//    else {
//        perror("Invalid Result");
//        EXIT_FAILURE;
//    }
//}
//
//int multiply(int n1, int n2) {
//    convert_both_to_dec(n1, n2);
//    if ((isValid(n1 * n2))) { return atoi(dec2bin((int) (n1 * n2))); }
//    else {
//        perror("Invalid Result");
//
//    }
//}
//
//int divide(int n1, int n2) {
//    convert_both_to_dec(n1, n2);
//    if ((isValid(n1 * n2))) { return atoi(dec2bin((int) (n1 / n2))); }
//    else {
//        perror("Invalid Result");
//
//    }
//}
