//
// Created by Katarina Kulkova on 25.05.2019.
//

#ifndef SRC_DECODE_H
#define SRC_DECODE_H

#include "../emulator_utility/instruction.h"
#include "../emulator_utility/state.h"

instruction_type decode(uint32_t fetched);
instruction_type decodeMUL(instruction_type *instruction, uint32_t fetched);
instruction_type decodeDP(instruction_type *instruction, uint32_t fetched);
instruction_type decodeSDT(instruction_type *instruction, uint32_t fetched);
instruction_type decodeBR(instruction_type *instruction, uint32_t fetched);
instruction_type decodeHLT(instruction_type *instruction, uint32_t fetched);

#endif //SRC_DECODE_H
