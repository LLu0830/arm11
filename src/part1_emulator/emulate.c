#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "part1_emulator/emulate/pipeline.h"
#include "part1_emulator/emulator_utility/utility.h"
#include "part1_emulator/emulate/binaryFileLoader.h"
#include <math.h>
#include "part1_emulator/emulator_utility/state.h"

int main(int argc, char **argv) {
    struct stateOfMachine ARM11;

    ARM11.mem = binaryFileLoader(argv);
    memset(ARM11.registers, 0, 17);
    pipeline(ARM11);

    return EXIT_SUCCESS;
}

//void CPSR_cond(struct registers ARM_registers){
//    int fst4CPSR[4]={*ARM_registers,*(ARM_registers+1),*(ARM_registers+2),*(ARM_registers+3)};
//}