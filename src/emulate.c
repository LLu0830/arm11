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
    ARM_registers.reg = calloc(17, sizeof(uint32_t));
    uint32_t *mem = binaryFileLoader(argv);
    return EXIT_SUCCESS;
}