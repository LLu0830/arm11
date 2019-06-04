//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "readInstruction.h"
#include "tokenizer.h"
#include "../assembler_utility/table.h"

bool isLabel(char *string){
    return strchr(string, ':') != NULL;
}

void readInstruction(char line, assembler_instruction *instruction){
    if (!isLabel(line)) {
        tokenizer(line, instruction);
    }
}

