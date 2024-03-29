//
// Created by Katarina Kulkova on 25.05.2019.
//


#ifndef SRC_PIPELINE_H
#define SRC_PIPELINE_H


#include "../emulator_utility/state.h"
#include <stdbool.h>
#include "../emulator_utility/instruction.h"
#include <stdint.h>


void pipeline(struct stateOfMachine *ARM11);

struct pipes{
    uint32_t fetched;
    Instruction decoded;
    bool has_fetched;
    bool has_decoded;
};


//struct pipes pipe;

#endif //SRC_PIPELINE_H
