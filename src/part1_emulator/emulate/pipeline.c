//
// Created by Katarina Kulkova on 25.05.2019.
//

#include "pipeline.h"
#include <stdlib.h>
#include <stdio.h>
#include "../emulator_utility/utility.h"
#include "../fetch/fetch.h"
#include "../decode/decode.h"
#include "../execute/execute.h"
#include "../emulator_utility/DefinedTypes.h"

void pipeline(struct stateOfMachine *ARM11) {

    //fetching first Instruction
    struct pipes pipeP;

    struct pipes *pipe = &pipeP;

    //no Instruction has been fetched or decoded so far
    pipe->has_fetched = false;
    pipe->has_decoded = false;

    //three stage pipeline, terminates when ARM11 is not running
    while (1) {

        //executes decoded Instruction
        if (pipe->decoded.instructionType != HLT) {
            if (pipe->has_decoded) {
//                printf("execute in pipeline (fetched): %X\n", pipe->fetched);
//                printf("execute in pipeline (Instruction Type): %X\n", pipe->decoded.instructionType);

                execute(pipe, ARM11);
            }
        } else {
            break;
        }
        //sets condition of loop to false, thus terminating the program


        //decoding fetched Instruction
        if (pipe->has_fetched) {
//            printf("decode in pipeline (Instruction type before decode): %X\n", pipe->decoded.instructionType);
            pipe->decoded = decode(pipe->fetched);
//            printf("decode in pipeline (Instruction type after decode): %x\n", pipe->decoded.instructionType);
            pipe->has_decoded = true;
        }

        //fetching new Instruction
//        pipe->fetched = fetch(ARM11, ARM11->registers[PCPosition]);
        pipe->fetched = fetch(ARM11);
        pipe->has_fetched = true;

        //increasing program counter (PC)
        ARM11->registers[PCPosition] += 4;
    }
}

