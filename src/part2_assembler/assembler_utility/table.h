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
<<<<<<< HEAD
    char[] name;
=======
    char* name;
>>>>>>> 96b04056834fd425ef8ce10bff2a510e25ff8e5a
    uint32_t code;
} token;

typedef struct assembler_instruction{
    token *mnemonic;
    token *arg1;
    token *arg2;
    token *arg3;
    token *arg4;
    InstructionType type;
    uint32_t encoded;
    InstructionType type;
    uint32_t encoded;
} assembler_instruction;


typedef char* label;
typedef uint32_t * address;

typedef struct label_address{
<<<<<<< HEAD
    label label;
    address address;
=======
    label *label;
    address *address;

>>>>>>> 96b04056834fd425ef8ce10bff2a510e25ff8e5a
}label_address;



<<<<<<< HEAD
=======


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

>>>>>>> e7c1be3443743732a29b415379728e960c0afa47

>>>>>>> 96b04056834fd425ef8ce10bff2a510e25ff8e5a
#endif //SRC_TABLE_H

