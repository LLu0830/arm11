//
// Created by MANSHU WANG on 5/29/2019.
//
#include "executeDP.h"
#include "state.h"
#include "utility.h"

void helper(struct stateOfMachine state, uint32_t carryBit, OpCode operation, uint32_t i){
    switch (OpCode) {
        case AND:
        case EOR:
        case ORR:
        case TEQ:
        case TST:
        case MOV:
            // if i flag is zero then it is a shift operation
            if (!i) {
                change_bit(state.registers[CPSRPosition], 29, carryBit);
            }
            break;

        case ADD:
            if (result < rnValue || result < op2Value) {
                change_bit(state.registers[CPSRPosition], 29, 1);
            } else {
                change_bit(state.registers[CPSRPosition], 29, 0);
            }
            break;
        case SUB:
        case CMP:
            //rn - operand2
            if (op2Value > rnValue) {
                change_bit(state.registers[CPSRPosition], 29, 0);
            } else {
                change_bit(state.registers[CPSRPosition], 29, 1);
            }
            break;
        case RSB:
            // operand2 - rn
            if (rn - op2Value) {
                change_bit(state.registers[CPSRPosition], 29, 0);
            } else {
                change_bit(state.registers[CPSRPosition], 29, 1);
            }
            break;
    }
}