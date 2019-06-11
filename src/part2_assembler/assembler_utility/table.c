//
// Created by Lize Lu on 2019/6/4.
//

#include <stdlib.h>
#include <string.h>
#include "../assembler_utility/table.h"
#include "../../part1_emulator/emulator_utility/DefinedTypes.h"


label_address_list *initialize_list(void) {
    label_address_list *list = malloc(sizeof(label_address_list));
    label_address *header = initialize_pair();
    label_address *footer = initialize_pair();

    list->header = header;
    list->footer = footer;

    return list;
}

label_address *initialize_pair(void) {
    label_address *pair = calloc(1, sizeof(label_address));
    if (pair == NULL) {
        perror("allocList");
        exit(EXIT_FAILURE);
    }

//    pair->label = NULL;
//    pair->address = 0;
//    pair->next = NULL;
//    pair->prev = NULL;
    return pair;
}

void insert_pair(label_address *pair, label_address_list *list) {
//    label_address *aPair = allocList;
//    aPair = initialize_list();
//    aPair->label = pair->label;
//    aPair->address = pair->address;
//    aPair->next = NULL;
//
//    if (list->header == NULL) {
//        list->header = aPair;
//        list->footer = aPair;
//    } else {
//        aPair->prev = list->footer;
//        list->footer->next = aPair;
//        list->footer = aPair;
//    }
//    free(aPair);

    if (list->header == NULL) {
        list->header = pair;
        list->footer = pair;
    } else {
        list->footer->prev->next = pair;
        pair->prev = list->footer->prev;
        list->footer = pair;
    }
}

address lookup_address(label label) {
    label_address *i = list->header;
    while (i != NULL) {
        if (i->label == label)
            return i->address;
        i = (label_address *) i->next;
    }
    return 0;
}


//label_address *allocList(void) {
//    label_address *aPair = malloc(sizeof(label_address *));
//    if (aPair == NULL) {
//        perror("allocList");
//        exit(EXIT_FAILURE);
//    }
//    return aPair;
//}



