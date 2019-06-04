//
// Created by Rini Banerjee on 2019-05-25.
//

#include <stdlib.h>
#include "executeDP.h"
#include "../emulator_utility/state.h"
#include "../emulator_utility/utility.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "../emulator_utility/DefinedTypes.h"
#include <assert.h>
#include "../emulator_utility/instruction.h"

// Gets the result when Operand2 is an immediate value
void getValFromImmediateOp2(uint32_t op2, uint32_t *result) {
    uint32_t rotateAmount = get_n_bits(op2, 8, 4);
    uint32_t imm = get_n_bits(op2, 0, 8);
    *result = rotateRight(imm, rotateAmount * 2);
}

// Gets the result when Operand2 is a register
void getValFromRegisterOp2(uint32_t op2, uint32_t *result, uint32_t *carryBit, struct stateOfMachine *ARM11) {
    uint32_t rm = get_n_bits(op2, 0, 4);
    uint32_t valueInRM = ARM11->registers[rm];
    uint32_t lastBit = get_n_bits(op2, 4, 1);

//    Checks if the shift is by a constant amount
    if (lastBit == 0) {
        uint32_t shiftAmount = get_n_bits(op2, 7, 5);
        uint32_t shiftCode = get_n_bits(op2, 5, 2);

//        If shift is 0, nothing is changed and the result is the value in register rm
        if (shiftAmount == 0) {
            *result = valueInRM;
            return;

//        If shift is greater than 32, special cases need to be checked
        } else if (shiftAmount > 32) {
            switch (shiftCode) {
                case ROR:
                    shiftAmount = shiftAmount % 32;
                    *result = shiftRegister(valueInRM, shiftAmount, shiftCode);
                    break;
                case ASR: {
                    uint32_t bit31 = get_n_bits(valueInRM, 31, 1);
                    if (bit31) {
                        *result = 0xffff;
                    } else {
                        *result = 0;
                    }
                    break;
                }
                default:
                    *result = 0;
                    *carryBit = 0;
                    return;
            }
//        If 0 < shiftAmount < 32, helper function used
        } else {
            *result = shiftRegister(valueInRM, shiftAmount, shiftCode);
        }

//      Carry bit calculated based on type of shift
        if (shiftCode == LSL) {
            *carryBit = get_n_bits(valueInRM, 32 - shiftAmount, 1);
        } else {
            *carryBit = get_n_bits(valueInRM, shiftAmount - 1, 1);
        }
    }
}

// Gets result and carry bit from Operand2
void getValFromOp2(uint32_t op2, bool i, uint32_t *result, uint32_t *carryBit, struct stateOfMachine *ARM11) {
    *result = 0;
    if (i) {
        getValFromImmediateOp2(op2, result);
    } else {
        getValFromRegisterOp2(op2, result, carryBit, ARM11);
    }

}

//Gets result from value in register rn and value obtained from Operand2, using opCode
uint32_t getResult(uint32_t opCode, uint32_t rnValue, uint32_t op2Value, bool *writeFlag) {
    uint32_t result;
    switch (opCode) {
        case AND:
            result = rnValue & op2Value;
            break;
        case EOR:
            result = rnValue ^ op2Value;
            break;
        case SUB:
            result = rnValue - op2Value;
            break;
        case RSB:
            result = op2Value - rnValue;
            break;
        case ADD:
            result = rnValue + op2Value;
            break;
        case TST:
            result = rnValue & op2Value;
            *writeFlag = 0;
            break;
        case TEQ:
            result = rnValue ^ op2Value;
            *writeFlag = 0;
            break;
        case CMP:
            result = rnValue - op2Value;
            *writeFlag = 0;
            break;
        case ORR:
            result = rnValue | op2Value;
            break;
        case MOV:
            result = op2Value;
            break;
        default:
            result = 0;
            break;
    }
    return result;
}


//Executes Data Processing Instruction
void executeDP(Instruction instruction, struct stateOfMachine *ARM11) {
    bool i = instruction.I;
    uint32_t opCode = instruction.operationType;
    bool s = instruction.S;
    int rn = instruction.rn;
    int rd = instruction.rd;
    uint32_t op2 = instruction.offsets_or_operand2;


//    Checks that register number is valid for ARM11
    assert(rn >= 0 && rn <= 16);
    uint32_t rnValue = ARM11->registers[rn];
    uint32_t op2Value;
    uint32_t carryBit = get_n_bits(ARM11->registers[16], 29, 1);
    getValFromOp2(op2, i, &op2Value, &carryBit, ARM11);

    bool writeFlag = 1;
//    Gets result and uses writeFlag to find out whether it needs to be written to memory
    uint32_t result = getResult(opCode, rnValue, op2Value, &writeFlag);


//    Writes result to memory if writeFlag is true
    if (writeFlag) {
        ARM11->registers[rd] = result;
    }


//    If the S bit is not set, none of the CPSR flags are changed
    if (!s) {
        return;
    }

    //    Sets C bit
    switch (opCode) {
        case AND:
        case EOR:
        case TST:
        case TEQ:
        case ORR:
        case MOV:
            setC(ARM11, carryBit);
            break;
        case ADD:
            // Checks for unsigned overflow
            if (result < op2Value || result < rnValue) {
                setC(ARM11, 1);
            }
            break;
        case SUB:
        case CMP:
            //rn - operand2
            setC(ARM11, (uint32_t) (op2Value <= rnValue));
            break;

        case RSB:
            // operand2 - rn
            setC(ARM11, (uint32_t) (op2Value >= rnValue));
            break;
        default:
            break;
    }

//    Sets Z bit

    if (result == 0) {
        setZ(ARM11, 1);
    }

//    Sets N bit

    uint32_t bit31 = get_n_bits(result, 31, 1);
    setN(ARM11, bit31);

}



