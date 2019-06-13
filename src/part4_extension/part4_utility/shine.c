//
// Created by ll7818 on 11/06/19.
//
#include <stdlib.h>
#include <string.h>
//#include "RPI.h"
//#include <wiringPi.h>

#define LED1 0
#define LED2 1
#define LED3 2
//
//void blink(char *n) {
//    wiringPiSetup();
//
//// LED Pin - wiringPi pin 0 is BCM_GPIO 17
////1 is 18
////2 is 21
//    if (!strcmp(n[0], '1')) {
//        pinMode(LED1, OUTPUT);
//        digitalWrite(LED1, 1);
//    }
//
//    if (!strcmp(n[1], '1')) {
//        pinMode(LED2, OUTPUT);
//        digitalWrite(LED2, 1);
//    }
//
//    if (!strcmp(n[2], '1')) {
//        pinMode(LED3, OUTPUT);
//        digitalWrite(LED3, 1);
//    }
//
//    delay(600);
//    digitalWrite(LED1, 0);
//    digitalWrite(LED2, 0);
//    digitalWrite(LED3, 0);
//    delay(400);
//}

//void mode_LED(int n) {
//    wiringPiSetup();
//    pinMode(LED1, OUTPUT);
//    int t = 0;
//    if (n == 1) {
//        digitalWrite(LED1, 1);
//        delay(500);
//        digitalWrite(LED1, 0);
//        delay(300);
//    }
//    if (n == 2) {
//        while (t < 2) {
//            digitalWrite(LED1, 1);
//            delay(500);
//            digitalWrite(LED1, 0);
//            delay(200);
//            t++;
//        }
//    }
//    if (n == 3) {
//        while (t < 3) {
//            digitalWrite(LED1, 1);
//            delay(500);
//            digitalWrite(LED1, 0);
//            delay(200);
//            t++;
//        }
//    }
//
//}

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
