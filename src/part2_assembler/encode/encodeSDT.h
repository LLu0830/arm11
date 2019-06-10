//
// Created by Katarina Kulkova on 02.06.2019.
//

#ifndef SRC_ENCODESDT_H
#define SRC_ENCODESDT_H

#include "../assembler_utility/table.h"

uint32_t concatSDT(uint32_t cond, uint32_t bit_value_1, uint32_t I_bit, uint32_t P_bit, uint32_t U_bit,
                   uint32_t L_bit, uint32_t rn, uint32_t rd, uint32_t offset);
uint32_t getValue(char *string);
void encodeSDT(assembler_instruction *instruction);

#endif //SRC_ENCODESDT_H
