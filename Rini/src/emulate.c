#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    FILE *fp;
    unsigned char c;
    fp = fopen(argv[0], "rb");

    while (!(feof(fp))) {
        c = fread();
    }
    return EXIT_SUCCESS;
}


