//
// Created by Katarina Kulkova on 02.06.2019.
//

#ifndef SRC_ENCODEBR_H
#define SRC_ENCODEBR_H

#include "../assembler_utility/table.h"

//void encodeBR(assembler_instruction *instruction);
uint32_t getCond(OpCode operationType);
void encodeBR(assembler_instruction *instruction, label_address_list *table);

#endif //SRC_ENCODEBR_H
