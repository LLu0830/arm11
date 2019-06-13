//#include <fcntl.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <unistd.h>
//#include <stdint.h>
//#include <time.h>
//#include <sys/ioctl.h>
//#include "linux/i2c-dev.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "part4_utility/shine.h"
#include "part4_utility/part4_utility.h"

#define MAX_CHAR_NUM 512
#define MAX_LINE_NUM 7


//reading commands from a file
int main(int argc, char **argv) {
    //int end, loop, line;
    //char str[MAX_CHAR_NUM];
    char *lines[MAX_LINE_NUM];
    FILE *fd = fopen("extension.txt", "r");
    if (fd == NULL) {
        perror("Empty File\n");
        EXIT_FAILURE;

    }
//        printf("Enter the line number to read : ");
//        scanf("%d", &line);

    fread(lines, sizeof(char), MAX_LINE_NUM, fd);
    int n = atoi(lines[1]);
    int n1 = atoi(lines[3]);
    int n2 = atoi(lines[4]);
    assert(isValid(n));
    if (isValid(n)) {
        //shines the led according to binary number
        shine(dec2bin(atoi(lines[1])));
    }

    int bin_result = operate_arith(n1, n2, lines[5]);
    shine(int_to_str(bin_result));

//
//    for (end = loop = 0; loop < MAX_LINE_NUM; ++loop) {
//        if (0 == fgets(str, sizeof(str), fd)) {//include '\n'
//            end = 1;//can't input (EOF)
//            break;
//        }
//    }
//
//    if (!end)
//        printf("\nLine-%d: %s\n", line, str);
    fclose(fd);

    return 0;
}


//reading commands from std input
void anotherMain(void) {
    int m;
    printf("Please select the mode, enter 1 for 3 bits binary counter, 2 for 3-bit binary numeroscope, 3 for numeroscope\nthat has enbeded arithmetic operation for 2 numbers");
    scanf("%d", &m);
    switch (m) {
        case 1:
            counter_main();
            break;
        case 2:
            presenter();
            break;
        case 3:
            mode_3();
            break;
    }
}


void presenter(void) {
    int n, b_int;
    char *b_str;
    printf("Mode 2, the LEDs are representing a decimal number entered\n")
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

void mode_3(void) {
    int n1, n2;
    char *operation_type;
    printf("Mode 3, do arithmetic operation on 2 numbers entered and represent the result with LEDs.\n")
    printf("Enter first of two integers you want to do arithmetic operation on (in decimal or binary number system)\n");
    scanf("%d", &n1);
    printf("Enter the type of operation(add,sub,mul,div\n");
    scanf("%s", &operation_type);
    printf("Enter second of two integers you want to do arithmetic operation on (in decimal or binary number system)\n");
    scanf("%d", &n2);
    int bin_result = operate_arith(n1, n2, operation_type);
    printf("The result of the operation is %d\n", bin_result);
    shine(int_to_str(bin_result));
    printf("Look at the LEDs!!");
}

//free(b_str);

//return 0;


//taking a 32_bit decimal int and convert it to binary number as a string


//    int fd;
//    struct timespec _500ms;
//    _500ms.tv_sec = 0;
//    _500ms.tv_nsec = 5000000L;
//    fd = open("/dev/i2c-1", O_RDWR);
//    if(fd < 0) {
//        fprintf(stderr, "Error opening device\n");
//        exit(EXIT_FAILURE);
//    }
//    if(ioctl(fd, I2C_SLAVE, 0x20) < 0) {
//        fprintf(stderr, "Error setting slave address\n");
//        close(fd);
//        exit(EXIT_FAILURE);
//    }
//
//    char buf[10];
//    buf[0] = 0x07; // IODIR PORT1
//    buf[1] = 0x00; // all output
//    if(write(fd, buf, 2) != 2) {
//        fprintf(stderr, "Error writing (1)\n");
//        close(fd);
//        exit(EXIT_FAILURE);
//    }
//    printf("Write success!\n");
//
//    nanosleep(&_500ms, NULL);
//
//    buf[0] = 0x01; // PORT1
//    buf[1] = 0xff; // output high
//    if(write(fd, buf, 2) != 2) {
//        fprintf(stderr, "Error writing (2)\n");
//        close(fd);
//        exit(EXIT_FAILURE);
//    }
//
//    close(fd);
//    printf("Done.\n");
//    exit(EXIT_SUCCESS);
