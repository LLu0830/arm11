//
// Created by Katarina Kulkova on 24.05.2019.
//

//#include <stdio.h>
#include "execute.h"
#include "registers.h"
#include "memory.h"
#include "executeDP.h"
#include "executeSDT.h"
#include "executeMUL.h"
#include "executeBR.h"
#include "instruction.h"
#include "state.h"

//executes all types of instructions
void execute(instruction_type instruction, struct stateOfMachine state) {
    switch (instruction.instructionType) {
        case 'DP':
            executeDP(struct registers ARM11_registers, uint32_t b);
            break;
        case 'MUL':
            executeMUL(instruction, state);
            break;
        case 'SDT':
            executeSDT(struct registers ARM11_registers, uint32_t b);
            break;
        case 'BR':
            executeBR(struct registers ARM11_registers, uint32_t b);
            break;
        default:
            break;
    }
}
