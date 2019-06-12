//
// Created by Katarina Kulkova on 02.06.2019.
//

#ifndef SRC_ENCODE_H
#define SRC_ENCODE_H

#include "../assembler_utility/table.h"

//void encode(assembler_instruction *instruction);
void encode(assembler_instruction *instruction, label_address_list *table);

#endif //SRC_ENCODE_H
