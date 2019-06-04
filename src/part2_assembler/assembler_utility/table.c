

//
// Created by Lize Lu on 2019/6/4.
//



#define SIZE 20

#include <lzma.h>
#include <stdlib.h>
#include "../assembler_utility/table.h"


struct label_address *labelArray[];
struct label_address *aPair;

int hashCode(
        label *label
) {
    return *label;
}

void insert_label(
        label *label, address *address) {
    struct label_address *aPair = (struct label_address *) malloc(sizeof(struct label_address *));
    *aPair->label = label;
    *aPair->address = address;
    int hashIndex = hashCode(label);
    while (labelArray[hashIndex])  != NULL && labelArray[hashIndex]->label != -1) {
//go to next cell
        ++hashIndex;

//wrap around the table
        hashIndex %= SIZE;
    }
    labelArray[hashIndex] = aPair;
}

//static instruction *createNewTable(uint16_t numOfInstru)
//
//        string_arrays_t *make_string_arrays(void) {
//    string_arrays_t *string_arrays = malloc(sizeof(string_arrays_t));
//    if (!string_arrays) {
//        perror("Unable to allocate memory for string arrays");
//        exit(EXIT_FAILURE);
//    }
//    string_arrays->max_elements = INITIAL_ARRAY_SIZE;
//    string_arrays->arrays = malloc(string_arrays->max_elements
//                                   * sizeof(string_array_t *));
//    if (!string_arrays->arrays) {
//        perror("Unable to allocate memory for string arrays");
//        exit(EXIT_FAILURE);
//    }
//    string_arrays->size = 0;
//    return string_arrays;
//}


