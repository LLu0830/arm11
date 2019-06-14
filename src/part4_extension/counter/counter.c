//
// Created by ll7818 on 2019/6/13.
//

#include <stdio.h>
#include "../part4_utility/shine.h"
#include <stdlib.h>
#include "../part4_utility/part4_utility.h"
#define MAX_SIZE 64
//binary counter
void counter_helper(int x, int ceil) {
    char* buffer=malloc(MAX_SIZE*sizeof(char));
    int n=x;
    sprintf(buffer, "%u%u%u\n",
            //(x>>3)&0x1,
            (x >> 2) & 0x1,
            (x >> 1) & 0x1,
            x & 0x1);
    printf("\nBinary number %s", buffer);
    shine(buffer);
    printf("Now it's representing decimal number %d in binary form\n", n);
    printf("It has passed %d seconds\n",n);
    if (x == ceil) return;
    else counter_helper(x + 1,ceil);
}

//counter's main function
void counter(int x) {
    printf("Mode 1, this is a 3-bit binary counter using raspberry pi and 3 LEDs\n");
    printf("Please enter the ceilling of this round of count (maximum is the decimal number 7)\n");
    int ceil=0x7u;
    scanf("%d",ceil);
    printf("The LEDs will present number from 0 to %d in binary format in this round of count",ceil);
    counter_helper(x,ceil);
}
