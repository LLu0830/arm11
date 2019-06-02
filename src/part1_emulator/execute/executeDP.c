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

void getValFromImmediateOp2(uint32_t op2, uint32_t *result) {
    uint32_t rotateAmount = get_n_bits(op2, 8, 4);
    uint32_t imm = get_n_bits(op2, 0, 8);
    *result = rotateRight(imm, rotateAmount * 2);
}

void getValFromRegisterOp2(uint32_t op2, uint32_t *result, uint32_t *carryBit, struct stateOfMachine *ARM11) {
    uint32_t rm = get_n_bits(op2, 0, 4);
    uint32_t valueInRM = ARM11->registers[rm];
    uint32_t lastBit = get_n_bits(op2, 4, 1);
    if (lastBit == 0) {
        uint32_t shiftAmount = get_n_bits(op2, 7, 5);
        uint32_t shiftCode = get_n_bits(op2, 5, 2);
        if (shiftAmount == 0) {
            *result = valueInRM;
//                printf("result - operand2 (shiftAmount = 0): %x\n", *result);
            return;
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
//                        printf("result - operand2 (shiftAmount > 32 and LSL or LSR): %x\n", *result);
                    return;
            }
        } else {
            *result = shiftRegister(valueInRM, shiftAmount, shiftCode);
        }

        if (shiftCode == LSL) {
            *carryBit = get_n_bits(valueInRM, 32 - shiftAmount, 1);
        } else {
            *carryBit = get_n_bits(valueInRM, shiftAmount - 1, 1);
        }
//            printf("result - operand2 - reached the end: %x\n", *result);
    }
}

void getValFromOp2(uint32_t op2, bool i, uint32_t *result, uint32_t *carryBit, struct stateOfMachine *ARM11) {
    *result = 0;
    if (i) {
        getValFromImmediateOp2(op2, result);
    } else {
//        printf("i is false\n");
        getValFromRegisterOp2(op2, result, carryBit, ARM11);
    }

}


uint32_t getResult(uint32_t opCode, uint32_t rnValue, uint32_t op2Value, bool *writeFlag) {
    uint32_t result;
    switch (opCode) {
        case AND:
//            printf("In AND\n");
//            printf("op2Value: %x\n", op2Value);
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

//uint32_t produceBorrow(uint32_t b1, uint32_t b2) {
//    for (int i = 0; i < 32; i++) {
//        printf("%x ", get_n_bits(b1, i, 1));
//        printf("%x\n", get_n_bits(b2, i, 1));
//        if (!get_n_bits(b1, i, 1) && get_n_bits(b2, i, 1)) {
//            printf("Inside produceBorrow, setC bit to: %x\n", 0);
//            return 0x0;
//        }
//    }
//    printf("Inside produceBorrow, setC bit to: %x\n", 1);
//    return 0x1;
//}

void executeDP(Instruction instruction, struct stateOfMachine *ARM11) {
    bool i = instruction.immediateOperand;
    uint32_t opCode = instruction.operationType;
    bool s = instruction.scc;
    int rn = instruction.rn;
    int rd = instruction.rd;
    uint32_t op2 = instruction.offsets_or_operand2;


    assert(rn >= 0 && rn <= 16);
    uint32_t rnValue = ARM11->registers[rn];
    uint32_t op2Value;
    uint32_t carryBit = get_n_bits(ARM11->registers[16], 29, 1);
    getValFromOp2(op2, i, &op2Value, &carryBit, ARM11);

    bool writeFlag = 1;
    uint32_t result = getResult(opCode, rnValue, op2Value, &writeFlag);


//    Checking if result needs to be written to register
    if (writeFlag) {
        ARM11->registers[rd] = result;
    }


    if (!s) {
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
//            printf("iFlag is %x\n", i);
            setC(ARM11, carryBit);
            break;

        case ADD:
            if (result < op2Value || result < rnValue) {
                setC(ARM11, 1);
            }
            break;
        case SUB:
        case CMP:
            //rn - operand2
//            printf("Inside CMP");
            setC(ARM11, (uint32_t) (op2Value <= rnValue));
//            setC(ARM11, produceBorrow(rnValue, op2Value));
            break;

        case RSB:
            // operand2 - rn
            setC(ARM11, (uint32_t) (op2Value >= rnValue));

//            setC(ARM11, produceBorrow(op2Value, rnValue));
            break;
        default:
            break;
    }

//    Setting Z bit

    if (result == 0) {
//        printf("Is changing CPSR ZFlag\n");
        setZ(ARM11, 1);
    }

//    Setting N bit

    uint32_t bit31 = get_n_bits(result, 31, 1);
//    printf("Is changing CPSR NFlag, the value is %x\n", bit31);
    setN(ARM11, bit31);

//    printf("CPSR value is: %08x\n", ARM11->registers[CPSRPosition]);

}



