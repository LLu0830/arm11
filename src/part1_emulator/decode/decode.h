//
// Created by Katarina Kulkova on 25.05.2019.
//

#ifndef SRC_DECODE_H
#define SRC_DECODE_H

#include "../emulator_utility/instruction.h"

instruction_type decode(struct stateOfMachine state, uint32_t fetched);
void decodeMUL(struct instruction_type instruction, uint32_t fetched);
void decodeDP(struct instruction_type instruction, uint32_t fetched);
void decodeSDT(struct instruction_type instruction, uint32_t fetched);
void decodeBR(struct instruction_type instruction, uint32_t fetched);
void decodeHLT(struct instruction_type instruction, uint32_t fetched);

#endif //SRC_DECODE_H
