//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "readLabels.h"
#include "../assembler_utility/table.h"
#include "../emulator_utility/DefinedTypes.h"
#include "../assembler_utility/assembler_utility.h"
#include <string.h>


int charExist(char *str, char *sub) {
    char *p = (strstr(str, sub));
    if (p == NULL)
        return 0;
}

//instruction->currentAddress=counter;

void readLabels(label_address_list *table, FILE *file) {
    //generalize a new table if there isn't one

    if (table == NULL)
        table = initialize_list();
    uint32_t lineNum = 0, currentindex = 0;
    char *currentLabel = calloc(512, sizeof(char));
    char *temp = currentLabel;
    while (fgets(temp, 512, file) != NULL) {
        //removes the \n at the end of every line
        temp = strtok(temp, "\n");
        if (strstr(temp, ':') == NULL && *temp != '\0') {
            lineNum++;
        } else {
            label_address *pair = initialize_pair();
            pair->label = strcspn(temp, ":");
            pair->address = lineNum;
            insert_pair(*pair, table);
            currentindex++;
        }
        free(currentLabel);
        uint32_t *result = calloc(2, sizeof(uint32_t));
        result[1] = lineNum;
        result[0] = currentindex;

    }
}

