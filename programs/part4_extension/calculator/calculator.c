//
// Created by ASUS on 2019/6/13.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../part4_utility/shine.h"
#include "../part4_utility/part4_utility.h"

void calculator(void) {
    int n1, n2;
    char *operation_type=malloc(4*sizeof(char));
    printf("Mode 3, do arithmetic operation on 2 numbers entered and represent the result with LEDs.\n");
    printf("Enter first of two integers you want to do arithmetic operation on (in decimal or binary number system)\n");
    scanf("%d", &n1);
    printf("Enter the type of operation(add,sub,mul,div)\n");
    scanf("%s", operation_type);
    printf("Enter second of two integers you want to do arithmetic operation on (in decimal or binary number system)\n");
    scanf("%d", &n2);
    int bin_result = operate_arith(n1, n2, operation_type);
    printf("The result of the operation in binary form is %d\n", bin_result);
    shine(int_to_str(bin_result));
    printf("Look at the LEDs!!");
}
