//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../emulator_utility/instruction.h"
#include "executeSDT.h"
#include "../emulator_utility/state.h"
#include "../emulator_utility/utility.h"

void executeSDT(instruction instruction, struct stateOfMachine *state) {


    uint32_t iFlag = instruction.immediateOffset;
    uint32_t pFlag = instruction.Pre_Post;
    uint32_t uFlag = instruction.upBit;
    uint32_t lFlag = instruction.storeBit;
    uint32_t rn = instruction.rn; //base register
    uint32_t rd = instruction.rd;  //source/destination register
    uint32_t offset = instruction.offsets_or_operand2;

    uint32_t address;

    //Offset is immediate offset or shifted register
    if  (iFlag) {
        //offset is shifted register
        uint32_t shift;
        uint32_t rm = get_n_bits(offset, 0, 4);
        uint32_t rmContent = state->registers[rm];
        uint32_t intOrReg = get_n_bits(offset, 4, 1);
        uint32_t shiftType = get_n_bits(offset, 5, 2);

        if (intOrReg) {
            //shift specified by constant amount
            shift = get_n_bits(offset, 7, 5);
        }
        else {
            //shift specified by register rs
            uint32_t rs = get_n_bits(offset, 8, 4);
            uint32_t rsContent = state->registers[rs];
            //should be last byte of rs, is it it though??? :
            shift = get_n_bits(rsContent, 0, 8);
            //could also be get_n_bits(rsContent, 24, 8); ???
        }

        rmContent = state->registers[rm];
        offset = shiftRegister(rmContent, shift, shiftType);
    }

    //decides whether to add or subtract the offset
    if (!uFlag) {
        offset = - offset;
    }

    //Uses post or pre indexing
    if (pFlag) {
        //add/subtract offset from base register before transferring data
        //pre-indexing
        // should not change base register
        address = state->registers[rn] + offset;
    }
    else {
        //add/subtract offset from base register after transferring data
        //post-indexing
        //changes base register
        address = state->registers[rn];
        state->registers[rn] = address + offset;
    }


    if (address > numOfAddresses || address < minAddress) {
        printf("Invalid memory access");
    }
    else {
        //Loads word from memory or stores word to memory
        if (lFlag) {
            //word loaded from memory
            state->registers[rd] = *((uint32_t * )(state->mem + address));
        } else {
            //word stored into memory
            *((uint32_t * )(state->mem + address)) = state->registers[rd];
        }
    }
}


