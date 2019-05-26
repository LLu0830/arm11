//
// Created by Katarina Kulkova on 24.05.2019.
//

//#include <stdio.h>
#include "execute.h"
//#include "registers.h"
//#include "memory.h"
//#include "executeDP.h"
//#include "executeSDT.h"
//#include "executeMUL.h"
//#include "executeBR.h"
#include "instruction.h"


//executes all types of instructions
void execute() {
    switch (instructionType) {
        case 'DP':
            executeDP(struct registers ARM11_registers, uint32_t b);
            break;
        case 'MUL':
            executeMUL(struct registers ARM11_registers, uint32_t b);
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


bool checkCondition(instruction_type instruction) {
    Cond condition = instruction.conditionType;

    switch (condition) {
        case EQ:


        case NE:
    }

}