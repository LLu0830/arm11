//
// Created by Katarina Kulkova on 25.05.2019.
//

#ifndef SRC_DECODE_H
#define SRC_DECODE_H

#include "../emulator_utility/instruction.h"
#include "../emulator_utility/state.h"

Instruction decode(uint32_t fetched);
Instruction decodeMUL(Instruction *instruction, uint32_t fetched);
Instruction decodeDP(Instruction *instruction, uint32_t fetched);
Instruction decodeSDT(Instruction *instruction, uint32_t fetched);
Instruction decodeBR(Instruction *instruction, uint32_t fetched);
Instruction decodeHLT(Instruction *instruction, uint32_t fetched);

#endif //SRC_DECODE_H
