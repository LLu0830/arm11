//
// Created by ll7818 on 2019/6/13.
//

#include <stdio.h>
#include "shine.h"
#include <stdlib.h>
#include <string.h>
#include "../part4_utility/part4_utility.h"
#define MAX_SIZE 64
#define MAX_INT 21474836
//mode2


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
    printf("Now it's representing the last 3 bits of decimal number %d in binary form\n", n);
    printf("It has passed %d seconds\n",n);
    printf("Press Ctrl+C to terminate.");
    if (x == ceil) return;
    else counter_helper(x + 1,ceil);
}

//counter's main function
void counter(int x) {
    printf("Mode 1, this is a 3-bit binary counter using raspberry pi and 3 LEDs\n");
    printf("Please enter the ceilling of this round of count (the maximum number\n the LEDs are capable presenting is the decimal number 7)\n");
    printf("If you want to use this as a timer, enter \"timer\".\n");
    char *ceil_string=malloc(MAX_SIZE*sizeof(char));
    scanf("%s",ceil_string);
    int ceil=atoi(ceil_string);
    if(!strcmp(ceil_string,"timer")){
        printf("The machine will act as a timer with LEDs representing the first 3 bits of \n seconds that has passed");
    counter_helper(x,MAX_INT);
    return;}
    printf("The LEDs will present number from 0 to %d in binary format in this round of count",ceil);
    counter_helper(x,ceil);
}
