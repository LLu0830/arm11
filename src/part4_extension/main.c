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
#include "part4_utility.h"

int main(int argc, char **argv) {




//    {
//    int n, c, k, b;
//    int n1, n2;
//    char *dTob;
//
//    printf("Enter an integer in decimal number system\n");
//    scanf("%d", &n);
//
//    dTob = dec2bin(n);
//    b = atoi(dTob);
//    printf("Binary string of %d is: %s\n", n, dTob);
//
//    printf("Enter 2 integers in decimal or binary number system\n");
//    scanf("%d", "%d", &n1, &n2);
//
//    add(n1,n2);
//
//
//    free(dTob);
//
//    return 0;
//}

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
}