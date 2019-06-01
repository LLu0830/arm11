//
// Created by Katarina Kulkova on 25.05.2019.
//

#ifndef SRC_DECODE_H
#define SRC_DECODE_H

#include "../emulator_utility/instruction.h"
#include "../emulator_utility/state.h"

instruction decode(uint32_t fetched);
instruction decodeMUL(instruction *instruction, uint32_t fetched);
instruction decodeDP(instruction *instruction, uint32_t fetched);
instruction decodeSDT(instruction *instruction, uint32_t fetched);
instruction decodeBR(instruction *instruction, uint32_t fetched);
instruction decodeHLT(instruction *instruction, uint32_t fetched);

#endif //SRC_DECODE_H
