#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pipeline.h"
#include "memory.h"
#include "utility.h"
#include "binaryFileLoader.h"
#include "registers.h"
#include <math.h>

int main(int argc, char **argv) {
    struct registers ARM_registers;
    int size32 = sizeof(uint32_t);
    struct stateOfMachine* state = createNewState();
    ARM_registers.reg = calloc(17, size32);
    *mem = calloc((pow(2, 16) / size32), size32);
    binaryFileLoader(argc, **argv);

    return EXIT_SUCCESS;
}