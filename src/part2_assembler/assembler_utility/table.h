//
// Created by Katarina Kulkova on 02.06.2019.
//

#ifndef SRC_TABLE_H
#define SRC_TABLE_H

#include <stdlib.h>
#include <stdint.h>
#include "../../part1_emulator/emulator_utility/DefinedTypes.h"
//we should probably move DefinedTypes.h somewhere more accessible

//insert table here

typedef struct {
    char name[];
    uint32_t code;
}token;

typedef struct {
    token mnemonic;
    token operand1;
    token operand2;
    token operand3;
    token operand4;

    InstructionType type;
    uint32_t encoded;

}parsed;
//called it parsed, since I figured instruction would not be a great name
//due to the fact we already have a struct like that and would be confusing
//I guess we can rename it later

#endif //SRC_TABLE_H
