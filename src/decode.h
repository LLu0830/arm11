//
// Created by Katarina Kulkova on 25.05.2019.
//

#ifndef SRC_DECODE_H
#define SRC_DECODE_H

bool checkCondition(struct stateOfMachine state, Cond condition);
void decode(struct stateOfMachine state, uint32_t fetched, instruction_type instruction);
void decodeMUL(instruction_type instruction, uint32_t fetched);
void decodeDP(instruction_type instruction, uint32_t fetched);
void decodeSDT(instruction_type instruction, uint32_t fetched);
void decodeBR(instruction_type instruction, uint32_t fetched);

#endif //SRC_DECODE_H
