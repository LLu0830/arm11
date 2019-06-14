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
#include "shine.h"
#include "part4_utility.h"
#include "presenter.h"
#include "calculator.h"
#include "counter.h"
#include <wiringPi.h>

#define MAX_CHAR_NUM 512
#define MAX_LINE_NUM 7


//reading commands from std input
int main(int argc,char** argv) {
    int m;
    printf("Please select the mode, enter 1 for 3 bits binary counter, 2 for 3-bit \nrepresenter, 3 for calculator for 2 numbers\n");
    scanf("%d", &m);
    switch (m) {
        case 1:
            mode_LED(1);
            counter(1);
            break;
        case 2:
            mode_LED(2);
            presenter();
            break;
        case 3:
            mode_LED(3);
            calculator();
            break;
        default :
            perror("Invalid mode input");
            EXIT_FAILURE;
    }
    return 1;
}




