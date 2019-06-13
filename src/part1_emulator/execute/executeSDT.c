

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

static const uint32_t CLEAR_ADDRESS = 0x20200028;
static const uint32_t SET_ADDRESS = 0x2020001C;
static const uint32_t GPIO_0_TO_9 = 0x20200000;
static const uint32_t GPIO_10_TO_19 = 0x20200004;
static const uint32_t GPIO_20_TO_29 = 0x20200008;


void executeSDT(Instruction instruction, struct stateOfMachine *state) {


    bool iFlag = instruction.immediateOffset;
    bool pFlag = instruction.Pre_Post;
    bool uFlag = instruction.upBit;
    bool lFlag = instruction.L;
    uint32_t rn = instruction.rn; //base register
    uint32_t rd = instruction.rd;  //source/destination register
    uint32_t offset = instruction.offsets_or_operand2;

    uint32_t address;

    //Offset is immediate offset or shifted register
    if (iFlag) {
        //offset is shifted register
        uint32_t shift;
        uint32_t rm = get_n_bits(offset, 0, 4);
        uint32_t rmContent = state->registers[rm];
        uint32_t intOrReg = get_n_bits(offset, 4, 1);
        uint32_t shiftType = get_n_bits(offset, 5, 2);

        if (!intOrReg) {
            //shift specified by constant amount
            shift = get_n_bits(offset, 7, 5);
        } else {
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
        offset = -offset;
    }

    //Uses post or pre indexing
    if (pFlag) {
        //add/subtract offset from base register before transferring data
        //pre-indexing
        // should not change base register
        address = state->registers[rn] + offset;
    } else {
        //add/subtract offset from base register after transferring data
        //post-indexing
        //changes base register
        address = state->registers[rn];
        state->registers[rn] = address + offset;
    }


    if (address == CLEAR_ADDRESS) {
        printf("PIN OFF\n");
//        return;
    }

    if (address == SET_ADDRESS) {
        printf("PIN ON\n");
//        return;
    }

    if (address == GPIO_0_TO_9) {
        printf("One GPIO pin from 0 to 9 has been accessed\n");
//        return;
    } else if (address == GPIO_10_TO_19) {
        printf("One GPIO pin from 10 to 19 has been accessed\n");
//        return;
    } else if (address == GPIO_20_TO_29) {
        printf("One GPIO pin from 20 to 29 has been accessed\n");
//        return;
    }


//    if ((address > numOfAddresses || address < minAddress) && (address < GPIO_0_TO_9 || address > CLEAR_ADDRESS)) {
//        printf("Error: Out of bounds memory access at address 0x%08x\n", address);
//    } else {
        //Loads word from memory or stores word to memory
        if (lFlag) {
            //word loaded from memory
            if (address > numOfAddresses) {
                state->registers[rd] = address;
            } else {
                state->registers[rd] = *((uint32_t *) (state->mem + address));
            }
        } else {
            //word stored into memory
            *((uint32_t *) (state->mem + address)) = state->registers[rd];
        }
//    }
}



