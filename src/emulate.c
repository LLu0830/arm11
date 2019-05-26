#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pipeline.h"
#include "memory.h"
#include "binaryFileLoader.h"
#include "registers.h"
#include <math.h>

//A message to Rini from Rini: HELLO!

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