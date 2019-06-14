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

// reads from file and stores labels in a table
void readLabels(label_address_list *table, FILE *file) {
    //check if the file is empty
    if (file == NULL) {
        perror("Error: file is empty.");
    }
    assert(table != 0);

    uint32_t lineNum = 0;

    char *currentLabel = calloc(MAX_LINE_SIZE, sizeof(char));
    char *temp = currentLabel;
    int cnt = 0;
    while (fgets(temp, MAX_LINE_SIZE, file) != NULL) {
        //removes the \n at the end of every line
        if (*temp != '\n' && temp != NULL) {
            if (!isLabel(temp) && *temp != '\0') {
                lineNum++;
                numOfAddress++;
                cnt++;
            } else {
                char *label = calloc(512, sizeof(char));
                label = strncpy(label, temp, strcspn(temp, ":"));
                label_address *pair = initialize_pair();
                assert(pair != 0);
                pair->label = label;
                pair->address = lineNum;
                printf("Adding label: \"%s\"\n", label);
                insert_pair(pair, table);
            }
        }
    }

}
