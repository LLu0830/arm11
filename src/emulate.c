#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pipeline.h"
#include "utility.h"
#include "binaryFileLoader.h"
#include <math.h>
#include "state.h"

int main(int argc, char **argv) {
    struct stateOfMachine ARM11;
    ARM11.registers = calloc(17, sizeof(uint32_t));
    ARM11.mem = binaryFileLoader(argv);
    return EXIT_SUCCESS;
}