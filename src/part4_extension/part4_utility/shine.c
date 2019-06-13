//
// Created by ll7818 on 11/06/19.
//
#include <stdlib.h>
#include "RPI.h"

void shine(char *n) {
    if (map_peripheral(&gpio) == -1) {
        perror("Failed to map the physical GPIO registers into the virtual memory space.\n");
        EXIT_FAILURE;
    }

    if (n[0]) {
        // Define pin 7 as output
        INP_GPIO(4);
        OUT_GPIO(4);

//    while(n=='1')
//    {
        // Toggle pin 7 (blink a led!)


        //makes the led shine
        GPIO_SET = 1 << 4;
        //sleep(1);


    }

    if (n[1]) {
        //define pin 21 as output
        INP_GPIO(5);
        OUT_GPIO(5);

        //toggle pin 21
        GPIO_SET = 1 << 5;


    }
    if (n[2]) {

        //define pin 22 as output
        INP_GPIO(6);
        OUT_GPIO(6);

        //toggle pin 22
        GPIO_SET = 1 << 6;
    }


    //make it shine for 2 seconds
    sleep(2);

    //reset the pin to shot the led
    GPIO_CLR = 1 << 4;
    GPIO_CLR = 1 << 5;
    GPIO_CLR = 1 << 6;

    sleep(1);

    //return 0;
}
