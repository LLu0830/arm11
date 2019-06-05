//
// Created by Katarina Kulkova on 02.06.2019.
//

#ifndef SRC_READINSTRUCTION_H
#define SRC_READINSTRUCTION_H

#include <stdlib.h>
#include <stdint.h>
#include "../assembler_utility/table.h"

void readInstruction(FILE *file, int *counter, assembler_instruction *instruction);

#endif //SRC_READINSTRUCTION_H
