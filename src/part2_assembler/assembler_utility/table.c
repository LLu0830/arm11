//
// Created by Lize Lu on 2019/6/4.
//

#define SIZE 20

#include <stdlib.h>
#include <string.h>
#include "../assembler_utility/table.h"
#include "../emulator_utility/DefinedTypes.h"


label_address *aPair;
label_address_list *list;

label_address_list *initialize_list() {
    label_address_list *list;
    list->header = NULL;
    list->footer = NULL;
    return list;
}

label_address *initialize_pair() {
    label_address pair;
    pair.label = NULL;
    pair.address = NULL;
    pair.next = NULL;
    pair.prev = NULL;
    return &pair;
}

void insert_pair(label_address *pair, label_address_list *list) {
    label_address *aPair = allocList();
    aPair->label = pair->label;
    aPair->address = pair->address;
    strncpy(aPair->label, *pair->label, sizeof(aPair->label));
    aPair->next = NULL;

    if (list->header == NULL) {
        list->header = aPair;
        list->footer = aPair;
    } else {
        aPair->prev = list->footer;
        list->footer->next = aPair;
        list->footer = aPair;
    }
    free(aPair);
}

address lookup_pair(label *label) {
    label_address *i = list->header;
    while (i != NULL) {
        if (i->label = label)
            return i->address;
        i = i->next;
    }
    return NULL;
}


struct label_address *allocList(void) {
    struct label_address *aPair = (label_address *) malloc(sizeof(struct label_address *));
    if (aPair == NULL) {
        perror("allocList");
        exit(EXIT_FAILURE);
    }
    return aPair;
}




//int hashCode(
//        label *label
//) {
//    return *label;
//}
//

//  struct label_address *aPair = (struct label_address *) malloc(sizeof(struct label_address *));
//    *aPairlabel = label;
//    *aPair->address = address;
//    int hashIndex = hashCode(label);
//    while (labelArray[hashIndex])  != NULL && labelArray[hashIndex]->label != -1) {
////go to next cell
//        ++hashIndex;
//
////wrap around the table
//        hashIndex %= SIZE;
//    }
//    labelArray[hashIndex] = aPair;
//}

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


