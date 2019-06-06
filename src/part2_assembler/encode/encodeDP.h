//
// Created by Katarina Kulkova on 02.06.2019.
//

#ifndef SRC_ENCODEDP_H
#define SRC_ENCODEDP_H

#include "../assembler_utility/table.h"

uint32_t getExpressionFromOp2(token op2);
uint32_t getRegisterNumber(token reg);
void encodeDPCompute(assembler_instruction *assembler_instruction, Instruction *emulator_instruction);
void encodeDPAssign(assembler_instruction *assembler_instruction, Instruction *emulator_instruction);
void encodeDPSetFlags(assembler_instruction *assembler_instruction, Instruction *emulator_instruction);
void encodeDP(assembler_instruction *assembler_instruction);
uint32_t concatDP(Instruction *emulator_instruction);


#endif //SRC_ENCODEDP_H
