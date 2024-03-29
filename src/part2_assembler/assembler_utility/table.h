//
// Created by Katarina Kulkova on 02.06.2019.
//


#ifndef SRC_TABLE_H
#define SRC_TABLE_H



#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../../part1_emulator/emulator_utility/DefinedTypes.h"
#include "../../part1_emulator/emulator_utility/instruction.h"


typedef char *token;
typedef char *label;
typedef uint32_t address;

extern uint32_t instruction_array[10];
extern int array_counter;


typedef struct {
    token mnemonic;
    token arg1;
    token arg2;
    token arg3;
    token arg4;
    token arg5;
    InstructionType type;
    OpCode operationType;
    uint32_t encoded;

    address target_address;
    address currentAddress;

} assembler_instruction;

extern int numOfAddress;



typedef struct label_address{
    label label;
    address address;
    struct label_address *prev;
    struct label_address *next;
} label_address;


typedef struct {
    label_address *header;
    label_address *footer;
} label_address_list;


label_address_list *initialize_list();

label_address *initialize_pair();

bool isContainedInTable(label label, label_address_list *table);

void insert_pair(label_address* pair, label_address_list *list);

address lookup_address(label label, label_address_list *table);



#endif //SRC_TABLE_H

