//
// Created by Lize Lu on 2019/6/4.
//

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../assembler_utility/table.h"
#include "../../part1_emulator/emulator_utility/DefinedTypes.h"


label_address_list *initialize_list(void) {
    label_address_list *list = malloc(sizeof(label_address_list));
    label_address *header = initialize_pair();
    label_address *footer = initialize_pair();

    list->header = header;
    list->footer = footer;

    header->next = footer;
    footer->prev = header;

    return list;
}

label_address *initialize_pair(void) {
    label_address *pair = calloc(1, sizeof(label_address));
    if (pair == NULL) {
        perror("allocList");
        exit(EXIT_FAILURE);
    }

    return pair;
}

void insert_pair(label_address *pair, label_address_list *list) {
    pair->prev = list->footer->prev;
    pair->next = list->footer;
    list->footer->prev = pair;
    pair->prev->next = pair;
}

address lookup_address(label label, label_address_list *table) {
    label_address *i = table->header->next;
    while (i != table->footer) {
        if (strcmp(i->label, label) == 0) {
            return i->address;
        }
        i = i->next;
    }
    return 0;
}

bool isContainedInTable(label label, label_address_list *table){
    label_address *i = table->header->next;
    while (i != table->footer) {
        if (!strcmp(i->label,label)) {
            return 1;
        }
        i = i->next;
    }
    return 0;
}



