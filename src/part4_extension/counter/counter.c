//
// Created by ASUS on 2019/6/13.
//

#include <stdio.h>
#include "../part4_utility/shine.h"
#include <stdlib.h>
#include "../part4_utility/part4_utility.h"
#define MAX_SIZE 64
//binary counter
void counter_helper(int x) {
    char* buffer=malloc(MAX_SIZE*sizeof(char));
    sprintf(buffer, "%u%u%u\n",
            //(x>>3)&0x1,
            (x >> 2) & 0x1,
            (x >> 1) & 0x1,
            x & 0x1);
    printf("%s", buffer);
    shine(buffer);
    printf("Now it's representing %s\n", buffer);
    if (x == 0x7U) return;
    else counter_helper(x + 1);
}

//counter's main function
void counter(int x) {
    printf("Mode 1, this is a 3-bit binary counter using raspberry pi and 3 LEDs\n");
    counter_helper(x);
}