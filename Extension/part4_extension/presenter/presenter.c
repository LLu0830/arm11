//
// Created by ASUS on 2019/6/13.
//

#include "presenter.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../part4_utility/shine.h"
#include "../part4_utility/part4_utility.h"
#include <string.h>

//mode 2
void presenter(void) {
    int n;
    char *b_str;
    printf("Mode 2, the LEDs are representing a decimal number entered\n");
    printf("Enter an integer in decimal number system\n");
    scanf("%d", &n);
    if (!isValid(n) || !isBin(int_to_str(n))) {
        printf("\nThe number entered is out of range (0 to 7). \nThe LEDs will be presenting the 3 most significant bits of it's binary form.\n");
    }

    b_str = dec2bin(n);

    printf("Binary form of %d is: %s\n", n, b_str);

    printf("Look at the LEDs!!\n");

    shine(b_str);
}
