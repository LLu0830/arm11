//
// Created by Katarina Kulkova on 25.05.2019.
//


#ifndef SRC_PIPELINE_H
#define SRC_PIPELINE_H

<<<<<<< HEAD
//pipeline function
void pipeline(struct stateOfMachine ARM11);
=======

#include <stdbool.h>

// define fetch, decode and execute functions probably??
// but if we do that here, we may not need their respective headers??? Am confused

// (Rini) Headers are like interfaces - you just write the names of the functions in the corresponding .c file, with the parameters included

>>>>>>> 84651c74bdb066eed4db975fabe2d5e7824acc9d

struct pipes{
    uint32_t fetched;
    instruction_type decoded;
    bool has_fetched;
};

void pipeline(struct stateOfMachine ARM11, struct pipes pipe);


//struct pipes pipe;

#endif //SRC_PIPELINE_H
