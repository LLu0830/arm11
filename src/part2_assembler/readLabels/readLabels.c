//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "readLabels.h"
#include "../assembler_utility/table.h"
#include "../emulator_utility/DefinedTypes.h"
#include "../assembler_utility/assembler_utility.h"
#include <string.h>

#define MAX_LINE_SIZE 512


void readLabels(label_address_list *table, FILE *file) {
    //check if the file is empty
    if (file == NULL) {
        perror("Error: file is empty.");
    }
    //generalize a new table if there isn't one
    if (table == NULL)
        table = initialize_list();
    uint32_t lineNum = 0;

    char *currentLabel = calloc(MAX_LINE_SIZE, sizeof(char));
    char *temp = currentLabel;
    while (fgets(temp, MAX_LINE_SIZE, file) != NULL) {
        //removes the \n at the end of every line
        //temp = strtok(temp, "\n");
        //strstr(temp, ':') == NULL
        if (!isLabel(temp) && *temp != '\0') {
            lineNum++;
            numOfAddress++;
        } else {
            char *label = calloc(512, sizeof(char));
            label = strncpy(label, temp, strcpy(strcspn(temp, ":"));
            label_address *pair = initialize_pair();
            pair->label = label;
            pair->address = lineNum + 1;
            insert_pair(pair, table);
            //currentindex++;
        }
        free(currentLabel);
//        uint32_t *result = calloc(2, sizeof(uint32_t));
//        result[1] = lineNum;
//        result[0] = currentindex;

    }

}

//void readLabels2(label_address_list *table, FILE *file) {
//    address counter=0;
//    //prints error if file pointer is NULL
//    if (file == NULL) {
//        printf("Error: file pointer is null.");
//    }
//
//        //reads one line from file
//    else if (file != NULL) {
//        label_address_list* table = initialize_list();
//        char line[MAX_LINE_SIZE];
//        fgets(line, sizeof line, file);
//        //counter++;
//
//
//        //if the line exists and is a label, it's put in the table
//        if (isLabel(line) && (line != NULL)) {
//
//        }
//        if (!isLabel(line) && (line != NULL)) {
//           counter++;
//
//
//        }
//        free(line);
//    }
//}