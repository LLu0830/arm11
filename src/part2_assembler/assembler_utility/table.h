//
// Created by Katarina Kulkova on 02.06.2019.
//

#ifndef SRC_TABLE_H
#define SRC_TABLE_H

//find out how to make hash map/ hash table?? in C an implement it here

//add the two structs
typedef struct {
    string name,
    uint32_t code
} token;

typedef struct {
    token mnemonic,
    token operand1,
    token operand2,
    token operand3,
    token operand4,
    InstructionType type,
    uint32_t encoded
} instruction;

#endif //SRC_TABLE_H
