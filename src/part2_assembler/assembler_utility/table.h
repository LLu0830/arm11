//
// Created by Katarina Kulkova on 02.06.2019.
//


#ifndef SRC_TABLE_H
#define SRC_TABLE_H


#include <stdlib.h>
#include <stdint.h>
#include "../../part1_emulator/emulator_utility/DefinedTypes.h"

typedef struct {
    char name[];
    uint32_t code;
}token;

typedef struct {
=======
#include <stdint.h>
#include "../emulator_utility/DefinedTypes.h"
#include "../emulator_utility/instruction.h"
//#include "assembler_utility.h"


typedef struct token{
    char[] name;
    uint32_t code;
} token;

typedef struct assembler_instruction{
    token mnemonic;
    token operand1;
    token operand2;
    token operand3;
    token operand4;
    InstructionType type;
    uint32_t encoded;
    InstructionType type;
    uint32_t encoded;
} assembler_instruction;

typedef char *label;
typedef int *address;

typedef struct label_address{
    label label;
    address address;
}label_address;



#endif //SRC_TABLE_H

