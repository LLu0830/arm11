//
// Created by ASUS on 2019/6/13.
//

#include "presenter.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../part4_utility/shine.h"
#include "../part4_utility/part4_utility.h"

void presenter(void) {
    int n, b_int;
    char *b_str;
    printf("Mode 2, the LEDs are representing a decimal number entered\n");
    printf("Enter an integer(range from 0 to 7) in decimal number system\n");

    if (!isValid(n)) {
        printf("Please enter a valid number");
    }
    scanf("%d", &n);
    b_str = dec2bin(n);
    b_int = atoi(b_str);
    printf("Binary form of %d is: %s\n", n, b_str);
    shine(b_str);
    printf("Look at the LEDs!!\n");
}