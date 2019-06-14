//
// Created by ll7818 on 11/06/19.
//
#include <stdlib.h>
#include <string.h>
//#include "RPI.h"
#include <wiringPi.h>

#define LED1 0
#define LED2 1
#define LED3 2

void shine(char *n) {

    wiringPiSetup();
    //delay(100);

// LED Pin - wiringPi pin 0 is BCM_GPIO 17
//1 is 18
//2 is 21
    if (*n == '1') {
        pinMode(LED1, OUTPUT);
        digitalWrite(LED1, 1);
    }

    if (*(n + 1) == '1') {
        pinMode(LED2, OUTPUT);
        digitalWrite(LED2, 1);
    }

    if (*(n + 2) == '1') {
        pinMode(LED3, OUTPUT);
        digitalWrite(LED3, 1);
    }

    delay(800);
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    delay(200);
}

void mode_LED(int n) {
    wiringPiSetup();
    pinMode(LED1, OUTPUT);
    int t = 0;
    if (n == 1) {
        digitalWrite(LED1, 1);
        delay(500);
        digitalWrite(LED1, 0);
        delay(300);
    }
    if (n == 2) {
        while (t < 2) {
            digitalWrite(LED1, 1);
            delay(500);
            digitalWrite(LED1, 0);
            delay(200);
            t++;
        }
    }
    if (n == 3) {
        while (t < 3) {
            digitalWrite(LED1, 1);
            delay(500);
            digitalWrite(LED1, 0);
            delay(200);
            t++;
        }
    }

}


