//
// Created by Katarina Kulkova on 02.06.2019.
//

#ifndef SRC_ASSEMBLER_UTILITY_H
#define SRC_ASSEMBLER_UTILITY_H

#include <stdint.h>
#include <stdbool.h>
#include "table.h"

uint32_t rotateLeft(uint32_t b, int n);
uint32_t rotateLeftNtimes(uint32_t b, int n);
char *copy_string(char *string);
//static bool is_label(char *instruction);
bool isLabel(char *string);
assembler_instruction *instruction_create(void);
void instruction_free(assembler_instruction *instruction);
uint32_t getValue(char *string);

#endif //SRC_ASSEMBLER_UTILITY_H
