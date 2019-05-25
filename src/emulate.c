#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dataprocessing_execute.h"
#include "registers.h"
#include <math.h>

int main(int argc, char **argv) {
    struct registers ARM_registers;
    int size32 = sizeof(uint32_t);
    ARM_registers.reg = calloc(17, size32);
    uint32_t *mem = calloc((pow(2, 16) / size32), size32);
    FILE *fp;
    fp = fopen(argv[0], "rb");
    while (!feof(fp)) {
        fread(mem, size32, 1, fp);
    }
    return EXIT_SUCCESS;
}