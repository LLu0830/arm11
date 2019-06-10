//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "readInstruction.h"
#include "../tokenizer/tokenizer.h"
#include "../assembler_utility/table.h"
#include "../assembler_utility/assembler_utility.h"

#define MAX_LINE_SIZE 512

//reads one instruction at a time and passes it to the tokenizer
void readInstruction(FILE *file, int *counter, assembler_instruction *instruction){

    //prints error if file pointer is NULL
    if (file == NULL) {
        printf("Error: file pointer is null.");
    }

    //reads one line from file
    else
    if (file != NULL)
    {
        char line[MAX_LINE_SIZE];
        fgets(line, sizeof(line), file);

        //if the line exists and is not a label, it is passed to the tokenizer
        if (!isLabel(line) && (line != NULL)) {
            counter++;
            instruction->currentAddress = (address) counter;
            tokenizer(line, instruction);
        }

    }
}

