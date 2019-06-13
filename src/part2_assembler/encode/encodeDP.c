//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "encodeDP.h"
#include "../assembler_utility/table.h"
#include <string.h>
#include "../../part1_emulator/emulator_utility/instruction.h"
#include "../assembler_utility/assembler_utility.h"
#include "../../part1_emulator/emulator_utility/utility.h"

uint32_t getRegisterNumber(token reg) {
//  ignoring the 'r' character to get the number from the register
    return (uint32_t) strtol(reg + 1, NULL, 10);
}

uint32_t getValueFromOp2(token op2Pointer, Instruction *emulator_instruction) {
    if (*op2Pointer == '#') {
        emulator_instruction->I = 1;
        uint32_t expression;
//      checks is expression is hexadecimal or decimal
        if (*(op2Pointer + 2) == 'x') {
            expression = (uint32_t) strtol(op2Pointer + 3, NULL, 16);
        } else {
            expression = (uint32_t) strtol(op2Pointer + 1, NULL, 10);
        }
        uint32_t count = 0;

//  checks if immediate value can be stored
        while (count <= 0xf) {
            if (expression <= 0xff) {
                count = count << 9U;
//   gets Operand2
                uint32_t result = expression | count;
                return result;
            }
            expression = rotateLeftNtimes(expression, 2);
            count++;
        }
        if (count > 30) {
            perror("This numeric constant cannot be represented.");
            return EXIT_FAILURE;
        }

    } else if (*op2Pointer == 'r') {
//   operand2 is set to have a shift of 0, and the register number is set to what has been specified
        emulator_instruction->I = 0;
        return getRegisterNumber(op2Pointer);
    }
    return getValueFromOp2(op2Pointer + 1, emulator_instruction);
}

uint32_t getValueFromOp2Optional(assembler_instruction *instruction, Instruction *emulator_instruction){

    emulator_instruction->I = 0;

    uint32_t reg_or_val_flag = 0;
    uint32_t shift_type = 0;
    uint32_t expression_value = getValue(instruction->arg4);
    uint32_t result;
    uint32_t rm = getValue(instruction->arg2);

    switch(instruction->arg3[0]) {
        case 'l':
            if (instruction->arg3[2] == 'l') {
                shift_type = 0;
            }
            if (instruction->arg3[2] == 'r') {
                shift_type = 1;
            }
            break;
        case 'a':
            shift_type = 2;
            break;
        case 'r':
            shift_type = 3;
            break;
        default:
            perror("Invalid shift type");
            exit(EXIT_FAILURE);
            break;
    }

    if (instruction->arg4[0] == '#'){
        reg_or_val_flag = 0;
    }
    else if (instruction->arg4[0] == 'r') {
        reg_or_val_flag = 1;
    }
    else {
        perror("Invalid argument");
        exit(EXIT_FAILURE);
    }

    shift_type = shiftLeft(shift_type, 5U);

    if (reg_or_val_flag){
        expression_value = shiftLeft(expression_value, 8U);
    }
    else {
        expression_value = shiftLeft(expression_value, 7U);
    }

    reg_or_val_flag = shiftLeft(reg_or_val_flag, 4U);

    result = expression_value | shift_type | reg_or_val_flag| rm;
    return result;

}


void encodeDPCompute(assembler_instruction *assembler_instruction, Instruction *emulator_instruction) {

//  getting number of destination register rd
    emulator_instruction->rd = getRegisterNumber(assembler_instruction->arg1);

//  getting number of base register rd
    emulator_instruction->rn = getRegisterNumber(assembler_instruction->arg2);

//  getting value from operand2
    emulator_instruction->offsets_or_operand2 = getValueFromOp2(assembler_instruction->arg3, emulator_instruction);

//  setting S bit to 0
    emulator_instruction->S = 0;
}

void encodeDPAssign(assembler_instruction *assembler_instruction, Instruction *emulator_instruction) {

//  rn not used here, so we can set it to any value
    emulator_instruction->rn = 0x0;

//  getting number of destination register rd
    emulator_instruction->rd = getRegisterNumber(assembler_instruction->arg1);

//  getting value from operand2
    if (assembler_instruction->arg3 == NULL) {
        emulator_instruction->offsets_or_operand2 = getValueFromOp2(assembler_instruction->arg2, emulator_instruction);
    }
    else {
        emulator_instruction->offsets_or_operand2 = getValueFromOp2Optional(assembler_instruction, emulator_instruction);
        printf("Optional case \n");
    }

//  setting S bit to 0
    emulator_instruction->S = 0;

}

void encodeDPSetFlags(assembler_instruction *assembler_instruction, Instruction *emulator_instruction) {

//  getting number of base register rn
    emulator_instruction->rn = getRegisterNumber(assembler_instruction->arg1);

//  rd not used here, so we can set it to any value
    emulator_instruction->rd = 0x0;

//  getting value from operand2
    emulator_instruction->offsets_or_operand2 = getValueFromOp2(assembler_instruction->arg2, emulator_instruction);

//  setting S bit to 1
    emulator_instruction->S = 1;
}

void encodeDP(assembler_instruction *assembler_instruction) {

    token mnemonic = assembler_instruction->mnemonic;
    Instruction emulator_instruction;
    switch (*mnemonic) {
        case 'm':
            encodeDPAssign(assembler_instruction, &emulator_instruction);
            break;
        case 't':
        case 'c':
            encodeDPSetFlags(assembler_instruction, &emulator_instruction);
            break;
        default:
            encodeDPCompute(assembler_instruction, &emulator_instruction);
            break;
    }

    emulator_instruction.conditionType = AL;
    emulator_instruction.operationType = (int) assembler_instruction->operationType;
    assembler_instruction->encoded = concatDP(&emulator_instruction);
    printf("encoded: %d", assembler_instruction->encoded);

}

uint32_t concatDP(Instruction *emulator_instruction) {
    uint32_t cond = emulator_instruction->conditionType << 28U;
    uint32_t i = emulator_instruction->I << 25U;
    uint32_t opCode = emulator_instruction->operationType << 21U;
    uint32_t s = emulator_instruction->S << 20U;
    uint32_t rn = emulator_instruction->rn << 16U;
    uint32_t rd = emulator_instruction->rd << 12U;
    uint32_t operand2 = emulator_instruction->offsets_or_operand2;
    return cond | i | opCode | s | rn | rd | operand2;
}
