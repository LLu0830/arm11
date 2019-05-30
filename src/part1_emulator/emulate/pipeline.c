//
// Created by Katarina Kulkova on 25.05.2019.
//

#include "pipeline.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "part1_emulator/emulator_utility/state.h"
#include "part1_emulator/emulator_utility/utility.h"
#include "part1_emulator/fetch/fetch.h"
#include "part1_emulator/decode/decode.h"
#include "part1_emulator/execute/execute.h"
#include "part1_emulator/emulator_utility/instruction.h"
#include "part1_emulator/emulator_utility/DefinedTypes.h"
#include "part1_emulator/emulator_utility/utility.c"

void pipeline(struct stateOfMachine ARM11) {

    //fetching first instruction
    struct pipes pipe;

    //no instruction has been fetched or decoded so far
    pipe.has_fetched = false;
    pipe.has_decoded = false;

    //three stage pipeline
    while (ARM11.running) {

        //executes decoded instruction
        if (pipe.has_decoded && pipe.decodedType != HLT) {
            execute(ARM11, pipe.decoded);
        }
        //sets condition of loop to false, thus terminating the program
        else {
            ARM11.running = false;
        }

        //decoding fetched instruction
        if (pipe.has_fetched) {
            pipe.decoded = pipe.fetched;
            pipe.has_decoded = true;
        }

        //fetching new instruction
        pipe.fetched = fetch(ARM11, ARM11->registers[PCPosition]);
        pipe.has_fetched = true;

        //increasing program counter (PC)
        ARM11->registers[PCPosition] += 4;
    }
}

