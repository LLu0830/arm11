//
// Created by Katarina Kulkova on 25.05.2019.
//


#ifndef SRC_PIPELINE_H
#define SRC_PIPELINE_H


#include "part1_emulator/emulator_utility/state.h"
#include <stdbool.h>
#include "part1_emulator/emulator_utility/instruction.h"


void pipeline(struct stateOfMachine ARM11);

struct pipes{
    uint32_t fetched;
    uint32_t decoded;
    InstructionType decodedType;
    bool has_fetched;
    bool has_decoded;
};


//struct pipes pipe;

#endif //SRC_PIPELINE_H
