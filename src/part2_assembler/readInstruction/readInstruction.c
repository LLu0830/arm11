//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include <stdint.h>
#include "readInstruction.h"
#include "tokenizer.h"
#include "../assembler_utility/table.h"

void readInstruction(char line[], parsed *instruction){
    if (!isLable(line)) {
        tokenizer(line, instruction);
    }
}

