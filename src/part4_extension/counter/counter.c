//
// Created by ASUS on 2019/6/13.
//

#include "../part4_utility/part4_utility.h"

//binary counter
void counter_helper(unsigned int x) {
    char buffer[3];
    sprintf(buffer, "%u%u%u\n",
            //(x>>3)&0x1,
            (x >> 2) & 0x1,
            (x >> 1) & 0x1,
            x & 0x1);
    printf("%s", buffer)
    shine(buffer);
    printf("Now it's representing %s\n", buffer);
    if (x == 0x7U) return;
    else counter_helper(x + 1);
}

//counter's main function
int counter(void) {
    printf("Mode 1, this is a 3-bit binary counter using raspberry pi and 3 LEDs\n");
    counter_helper(0);
}