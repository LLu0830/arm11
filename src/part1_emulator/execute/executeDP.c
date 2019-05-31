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

void getValFromOp2(uint32_t op2, uint32_t i, uint32_t *result, uint32_t *carryBit) {
    *result = 0;
    if (i == 1) {
        uint32_t rotateAmount = get_n_bits(op2, 8, 4);
        uint32_t imm = get_n_bits(op2, 0, 8);
        *result = rotateRight(imm, rotateAmount);
    } else {
        uint32_t valueInRM = get_n_bits(op2, 0, 4);
//        uint32_t shift = get_n_bits(op2, 4, 8);
        uint32_t lastBit = get_n_bits(op2, 4, 1);
        if (lastBit == 0) {
            uint32_t shiftAmount = get_n_bits(op2, 7, 5);
            if (shiftAmount == 0) {
                *result = valueInRM;
                *carryBit = 0;
            } else if (shiftAmount > 32) {
                *result = 0;
                *carryBit = 0;
            } else {
                uint32_t shiftCode = get_n_bits(op2, 5, 2);

                if (shiftCode == 0) {
                    *carryBit = get_n_bits(valueInRM, 32 - shiftAmount, 1);
                } else {
                    *carryBit = get_n_bits(valueInRM, shiftAmount - 1, 1);
                }
                switch (shiftCode) {
                    case 0:
                        *result = valueInRM << shiftAmount;
                        break;
                    case 1:
                        *result = valueInRM >> shiftAmount;
                        break;
                    case 2: {
                        int bit31 = get_n_bits(valueInRM, 31, 0);
                        *result = valueInRM >> shiftAmount;
                        if (bit31 != 0) {
                            uint32_t mask = makeASRmask(shiftAmount);
                            *result = *result | mask;
                        }
                        break;
                    }
                    case 3:
                        *result = rotateRight(valueInRM, shiftAmount);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}


uint32_t getResult(uint32_t opCode, uint32_t rnValue, uint32_t op2Value, int *writeFlag) {
    uint32_t result = 0;
    *writeFlag = 1;
    switch (opCode) {
        case 0:
            result = rnValue & op2Value;
            break;
        case 0x1:
            result = rnValue ^ op2Value;
            break;
        case 0x2:
            result = rnValue - op2Value;
            break;
        case 0x3:
            result = op2Value - rnValue;
            break;
        case 0x4:
            result = rnValue + op2Value;
            break;
        case 0x8:
            result = rnValue & op2Value;
            *writeFlag = 0;
            break;
        case 0x9:
            result = rnValue ^ op2Value;
            *writeFlag = 0;
            break;
        case 0xa:
            result = rnValue - op2Value;
            *writeFlag = 0;
            break;
        case 0xb:
            result = rnValue | op2Value;
            break;
        case 0xc:
            result = op2Value;
            break;
        default:
            break;
    }
    return result;
}




void executeDP(instruction_type instruction, struct stateOfMachine *ARM11) {
    uint32_t i = instruction.immediateOperand;
    uint32_t opCode = instruction.operationType;
    uint32_t s = instruction.scc;
    int rn = instruction.rn;
    int rd = instruction.rd;
    uint32_t op2 = instruction.offsets_or_operand2;



    assert(rn >= 0 && rn <= 16);
    uint32_t rnValue = ARM11->registers[rn];
    uint32_t op2Value, carryBit;
    getValFromOp2(op2, i, &op2Value, &carryBit);

    int writeFlag;
    uint32_t result = getResult(opCode, rnValue, op2Value, &writeFlag);


//    Checking if result needs to be written to register
    if (writeFlag) {
        ARM11->registers[rd] = result;
    }

    //shouldn't it be a pointer???
    uint32_t cpsr = ARM11->registers[16];
    setC(ARM11, 0);


    if (s) {
        return;
    }

    //    Setting C bit for operations not involving barrel shifter

    switch (opCode) {
        case AND:
        case EOR:
        case TST:
        case TEQ:
        case ORR:
        case MOV:
            // if i flag is zero then it is a shift operation
            setC(ARM11, carryBit);
            break;

        case ADD:
            if (result > 0xffff) {
                setC(ARM11, 1);
            }
            break;
        case SUB:
        case CMP:
            //rn - operand2
            if (op2Value < rnValue) {
                setC(ARM11, 1);
            }
            break;

        case RSB:
            // operand2 - rn
            if (rnValue < op2Value) {
                setC(ARM11, 1);
            }
            break;
        default:
            break;
    }

//    Setting Z bit

    if (result == 0) {
        setZ(ARM11, 1);
    }

//    Setting N bit

    uint32_t bit31 = get_n_bits(result, 31, 1);
    setN(ARM11, bit31);

}



