//
// Created by Katarina Kulkova on 25.05.2019.
//
#include "instruction.h"

#ifndef SRC_PIPELINE_H
#define SRC_PIPELINE_H

// define fetch, decode and execute functions probably??
// but if we do that here, we may not need their respective headers??? Am confused



struct pipes{
    uint32_t fetched;
    instruction_type decoded;
    bool has_fetched;
} pipe;

//struct pipes pipe;

#endif //SRC_PIPELINE_H
