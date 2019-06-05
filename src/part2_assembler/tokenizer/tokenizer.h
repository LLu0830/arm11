//
// Created by Katarina Kulkova on 02.06.2019.
//

#ifndef SRC_TOKENIZER_H
#define SRC_TOKENIZER_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../assembler_utility/table.h"

void tokenizer(char *instruction, assembler_instruction *parsed);

#endif //SRC_TOKENIZER_H
