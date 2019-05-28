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

    ARM11.mem = binaryFileLoader(argv);
    memset(ARM11.registers.registers, 0, 17);
    pipeline(ARM11);

    return EXIT_SUCCESS;
}

//void CPSR_cond(struct registers ARM_registers){
//    int fst4CPSR[4]={*ARM_registers,*(ARM_registers+1),*(ARM_registers+2),*(ARM_registers+3)};
//}