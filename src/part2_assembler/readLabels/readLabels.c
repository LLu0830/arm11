//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "readLabels.h"
#include "../assembler_utility/table.h"
#include "../../part1_emulator/emulator_utility/DefinedTypes.h"
#include "../assembler_utility/assembler_utility.h"
#include <string.h>
#include <assert.h>

#define MAX_LINE_SIZE 512

int numOfAddress = 0;

void readLabels(label_address_list *table, FILE *file) {
    //check if the file is empty
    if (file == NULL) {
        perror("Error: file is empty.");
    }
    assert(table != 0);
    //generalize a new table if there isn't one
//    if (table == NULL) {
//        table = initialize_list();
//    }
    uint32_t lineNum = 0;

    char *currentLabel = calloc(MAX_LINE_SIZE, sizeof(char));
//    char *temp =  calloc(MAX_LINE_SIZE, sizeof(char));
    char *temp = currentLabel;
    while (fgets(temp, MAX_LINE_SIZE, file) != NULL) {
        //removes the \n at the end of every line
        if (!isLabel(temp) && *temp != '\0') {
            lineNum++;
            numOfAddress++;
        } else {
            char *label = calloc(512, sizeof(char));
            label = strncpy(label, temp, strcspn(temp, ":"));
            label_address *pair = initialize_pair();
            assert(pair != 0);
            pair->label = label;
            pair->address = lineNum + 1;
            insert_pair(pair, table);
        }
    }
//    free(currentLabel);
}
