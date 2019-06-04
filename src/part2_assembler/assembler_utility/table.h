//
// Created by Katarina Kulkova on 02.06.2019.
//


#ifndef SRC_TABLE_H
#define SRC_TABLE_H

#include <stdint.h>
#include <stdio.h>
#include "../emulator_utility/DefinedTypes.h"
#include "../emulator_utility/instruction.h"
//#include "assembler_utility.h"


//find out how to make hash map/ hash table?? in C an implement it here

//add the two structs

typedef char *token;

typedef struct {
    token *mnemonic;
    token *arg1;
    token *arg2;
    token *arg3;
    token *arg4;

    InstructionType type;
    uint32_t encoded;
    int counter;//counter in readInstruction
} assembler_instruction;


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
}label_address_list;




//typedef struct {
//    /** Array of strings. */
//    char **array;
//    /** The number of strings in the array. */
//    uint16_t size;
//} string_array;
//
//typedef struct {
//    /** The label string, with maximum length of MAX_LABEL_LENGTH */
//    char label[MAX_LABEL_LENGTH + 1];
//    /** The address of this label */
//    address address;
//} table_row;
//
//typedef struct {
//    /** Maximum number of rows in symbol table. */
//    uint16_t max_size;
//    /** Number of rows in symbol table. */
//    uint16_t size;
//    /** An array of symbol table rows. */
//    table_row *rows;
//} table;
//
//table *generate_symbol_table(string_arrays *tokens);
//address get_address(table_t *table, char *label);
//void free_table(symbol_table_t *table);



#endif //SRC_TABLE_H

