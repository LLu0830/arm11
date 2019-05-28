#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "pipeline.h"
#include "utility.h"
#include "binaryFileLoader.h"
#include <math.h>
#include "state.h"

int main(int argc, char **argv) {
    struct stateOfMachine ARM11;
    memset(ARM11.registers, 0, 17);
    ARM11.mem = binaryFileLoader(argv);
    return EXIT_SUCCESS;
}