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
void presenter(void) {
    int n;
    char *b_str;
    printf("Mode 2, the LEDs are representing a decimal number entered\n");
    printf("Enter an integer(range from 0 to 7) in decimal number system\n");
    scanf("%d", &n);
    if (!isValid(n)||!isBin(int_to_str(n))) {
        printf("Please enter a valid binary number\n");
        EXIT_FAILURE;
    }
    
    b_str = dec2bin(n);
    if(strlen(b_str)==1){
        strcat(b_str,"00");}
        if(strlen(b_str)==2){
            strcat(b_str,"0");}
    printf("Binary form of %d is: %s\n", n, b_str);
   
    printf("Look at the LEDs!!\n"); 
    
    shine(b_str);
}
