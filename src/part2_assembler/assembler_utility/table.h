//
// Created by Katarina Kulkova on 02.06.2019.
//


#ifndef SRC_TABLE_H
#define SRC_TABLE_H


#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../emulator_utility/DefinedTypes.h"
#include "../emulator_utility/instruction.h"


//find out how to make hash map/ hash table?? in C an implement it here
typedef enum {
    and = 0x0,
    eor = 0x1,
    sub = 0x2,
    rsb = 0x3,
    add = 0x4,
    tst = 0x8,
    teq = 0x9,
    cmp = 0xa,
    orr = 0xc,
    mov = 0xd,
    mul,
    mla,
    ldr,
    str,
    beq,
    bne,
    bge,
    blt,
    bgt,
    ble,
    b,
    lsl,
    andeq
} Mnemonic;


//add the two structs


typedef char *token;
typedef char *label;
typedef uint32_t address;


typedef struct {
    token mnemonic;
    token arg1;
    token arg2;
    token arg3;
    token arg4;
    InstructionType type;
    Mnemonic operationType;
    uint32_t encoded;

    address target_address;
    address currentAddress;
    uint32_t counter;//counter in readInstruction

} assembler_instruction;

int numOfAddress=0;
typedef char *label;
typedef uint32_t address;


typedef struct {

    label label;
    address address;
    struct label_address *prev;
    struct label_address *next;
} label_address;


typedef struct {
    label_address *header;
    label_address *footer;
} label_address_list;


label_address *aPair;
label_address_list *list;

//do these have to be static?
static label_address_list *initialize_list();

static label_address *initialize_pair();

void insert_pair(label_address* pair, label_address_list *list);


static address lookup_address(label label);

static label_address *allocList(void);


#endif //SRC_TABLE_H

