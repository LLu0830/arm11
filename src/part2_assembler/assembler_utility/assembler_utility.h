//
// Created by Katarina Kulkova on 02.06.2019.
//

#ifndef SRC_ASSEMBLER_UTILITY_H
#define SRC_ASSEMBLER_UTILITY_H

#include <stdint.h>
#include <stdbool.h>
#include "table.h"

uint32_t rotateLeft(uint32_t b, int n);
char *copy_string(char *string);
bool isLabel(char *string);
assembler_instruction *instruction_create(void);
void instruction_free(assembler_instruction *instruction);
uint32_t getValue(char *string);
uint32_t get_shift_type(char *arg);
uint32_t getValueFromOp2Optional(char *reg, char *type, char *shift_value);

#endif //SRC_ASSEMBLER_UTILITY_H
