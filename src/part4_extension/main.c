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
#include "part4_utility.h"

#define MAX_CHAR_NUM 512
#define MAX_LINE_NUM 7

int main(int argc, char **argv) {
    int end, loop, line;
    char str[MAX_CHAR_NUM];
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
    if (isValid(n) && isValid(n1) && isValid(n2)) {
        //shines the led according to binary number
        shine(dec2bin(atoi(lines[1])));
    }

    int bin_result= operate_arith(n1,n2,lines[5]);
    shine(bin_result);

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