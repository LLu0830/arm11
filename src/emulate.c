#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) {
    FILE *fp;
    uint32_t *mem = calloc(16384, sizeof(uint32_t));
    fp = fopen(argv[0], "rb");
    while (!feof(fp)) {
        fread(mem, sizeof(uint32_t), 1, fp);
    }
    printf("Hello world.");
    return EXIT_SUCCESS;
}