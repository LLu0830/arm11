#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "emulate/pipeline.h"
#include "emulator_utility/utility.h"
#include "emulate/binaryFileLoader.h"
#include "emulator_utility/state.h"
#include "emulate/printOutput.h"
int main(int argc, char **argv) {
    struct stateOfMachine ARM11;

    ARM11.running = true;
    ARM11.mem = binaryFileLoader(argv);
    memset(ARM11.registers, 0, numOfRegisters * sizeof(uint32_t));

    pipeline(&ARM11);

    printOut(&ARM11);

    free(ARM11.mem);


    return EXIT_SUCCESS;
}
