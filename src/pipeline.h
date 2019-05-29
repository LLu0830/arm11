//
// Created by Katarina Kulkova on 25.05.2019.
//
#include "instruction.h"

#ifndef SRC_PIPELINE_H
#define SRC_PIPELINE_H

//pipeline function
void pipeline(struct stateOfMachine ARM11);

struct pipes{
    uint32_t fetched;
    instruction_type decoded;
    bool has_fetched;
} pipe;

//struct pipes pipe;

#endif //SRC_PIPELINE_H
