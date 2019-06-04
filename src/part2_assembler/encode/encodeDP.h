//
// Created by Katarina Kulkova on 02.06.2019.
//

#ifndef SRC_ENCODEDP_H
#define SRC_ENCODEDP_H

#include "../assembler_utility/table.h"

void encodeDPCompute(assembler_instruction *instruction);
void encodeDPAssign(assembler_instruction *instruction);
void encodeDPSetFlags(assembler_instruction *instruction);
void encodeDP(assembler_instruction *instruction);
uint32_t concatDP(assembler_instruction *instruction);


#endif //SRC_ENCODEDP_H
