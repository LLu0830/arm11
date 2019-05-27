#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pipeline.h"
#include "memory.h"
#include "binaryFileLoader.h"
#include "registers.h"
#include <math.h>

int main(int argc, char **argv) {
    struct registers ARM_registers;
<<<<<<< HEAD
    ARM_registers.reg = calloc(17, sizeof(uint32_t));
    uint32_t *mem = binaryFileLoader(argv);
=======
    int size32 = sizeof(uint32_t);
    ARM_registers.reg = calloc(17, size32);
    *mem = calloc((pow(2, 16) / size32), size32);
    binaryFileLoader(argc, **argv);

>>>>>>> dec3e21c2400928967b863e88f33ca1db3888950
    return EXIT_SUCCESS;
}