//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "binaryWriter.h"
#include <stdio.h>
#include "../assembler_utility/table.h"

//takes an instruction and a binary file, and writes instruction to file
void binaryWriter(uint32_t *instruction, FILE *fp_write) {
    fwrite(instruction, sizeof(uint32_t), 1, fp_write);
}