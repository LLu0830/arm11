//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "readInstruction.h"
#include "../tokenizer/tokenizer.h"
#include "../assembler_utility/table.h"
#include "../assembler_utility/assembler_utility.h"

#define MAX_LINE_SIZE 512
bool is_empty(char *line) {
  for (char *curr = line; *curr != '\0'; curr++) {
      if (!isspace(*curr)) {
          return false;
      }
  }
  return true;
}

//reads one instruction at a time and passes it to the tokenizer
bool readInstruction(FILE *file, int *counter, assembler_instruction *instruction) {

    //prints error if file pointer is NULL
    if (file == NULL) {
        printf("Error: file pointer is null.");
        return false;
    }

        //reads one line from file
    else {
        char *line = malloc(MAX_LINE_SIZE * sizeof(char));
        if (line == NULL) {
            perror("calloc in readInstruction");
            exit(EXIT_FAILURE);
        }

        if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
            return false;
        }

        //if the line exists and is not a label, it is passed to the tokenizer
        if (!isLabel(line) && (line != NULL) && !is_empty(line)) {
            instruction->currentAddress = (address) *counter;
            (*counter)++;
            tokenizer(line, instruction);
        } else {
            instruction->currentAddress = -1;
        }
        printf("Line: %s\n", line);

        free(line);
        return true;

    }
}