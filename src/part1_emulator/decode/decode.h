//
// Created by Katarina Kulkova on 25.05.2019.
//

#ifndef SRC_DECODE_H
#define SRC_DECODE_H

#include <part1_emulator/emulator_utility/instruction.h>

instruction_type decode(struct stateOfMachine state, uint32_t fetched);
void decodeMUL(instruction_type instruction, uint32_t fetched);
void decodeDP(instruction_type instruction, uint32_t fetched);
void decodeSDT(instruction_type instruction, uint32_t fetched);
void decodeBR(instruction_type instruction, uint32_t fetched);
void decodeHLT(instruction_type instruction, uint32_t fetched);

#endif //SRC_DECODE_H
