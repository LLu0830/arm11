//
// Created by Lize Lu on 2019/6/4.
//

#include <stdlib.h>
#include <string.h>
#include "../assembler_utility/table.h"
#include "../emulator_utility/DefinedTypes.h"



static label_address_list *initialize_list(void) {
    label_address_list *list;
    list->header = NULL;
    list->footer = NULL;
    return list;
}

static label_address *initialize_pair(void) {
    label_address pair;
    pair.label = NULL;
    pair.address = NULL;
    pair.next = NULL;
    pair.prev = NULL;
    return &pair;
}

void insert_pair(label_address *pair, label_address_list *list) {
    label_address *aPair = allocList;
    aPair->label = pair->label;
    aPair->address = pair->address;
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

static address lookup_address(label label) {
    label_address *i = list->header;
    while (i != NULL) {
        if (i->label == label)
            return i->address;
        i = (label_address *) i->next;
    }
    return NULL;
}


static label_address *allocList(void) {
    label_address *aPair = malloc(sizeof(label_address *));
    if (aPair == NULL) {
        perror("allocList");
        exit(EXIT_FAILURE);
    }
    return aPair;
}



