//
// Created by ASUS on 2019/6/11.
//
#include "part4_utility.h"

bool isBin(char *number) {
    int b, n;
    int length = strlen(number) - 1;
    for (int l = 0; l <= length; l++) {
        b = 1;
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

int bin2dec(char *binstr) {
    int dec = 0;
    int len = strlen(binstr);
    int i = 0;
    while (i < len) {
        dec = (dec << 1) + (binstr[i] - 0x30);
        i++;
    }
    return dec;
}

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

void convert_both_to_dec(int n1, int n2) {
    if (isBin(n1)) {
        char str1[(int) ((ceil(log10(n1)) + 1) * sizeof(char))];
        sprintf(str1, "%d", n1);
        n1 = bin2dec(str1);
    }
    if (isBin(n2)) {
        char str2[(int) ((ceil(log10(n2)) + 1) * sizeof(char))];
        sprintf(str2, "%d", n2);
        n2 = bin2dec(str1);
    }
}

int add(int n1, int n2) {
    convert_both_to_dec(n1, n2);
    if ((n1 + n2) >= 0 && (n1 + n2) <= 7) { return dec2bin((int) (n1 + n2)); }
    else {
        perror("Invalid Result");

    }
}

int subtract(int n1, int n2) {
    convert_both_to_dec(n1, n2);
    if ((n1 - n2) >= 0 && (n1 - n2) <= 7) { return dec2bin((int) (n1 - n2)); }
    else {
        perror("Invalid Result");

    }
}

int multiply(int n1, int n2) {
    convert_both_to_dec(n1, n2);
    if ((isValid(n1 * n2)) { return dec2bin((int) (n1 * n2)); }
            else {
        perror("Invalid Result");

    }
}

int divide(int n1, int n2) {
    convert_both_to_dec(n1, n2);
    if ((n1 / n2) >= 0 && (n1 / n2) <= 7) { return dec2bin((int) (n1 / n2)); }
    else {
        perror("Invalid Result");

    }
}
