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
#include "../execute/executeDP.h"

void executeSDT(Instruction instruction, struct stateOfMachine *state) {

    bool iFlag = instruction.immediateOffset;
    bool pFlag = instruction.Pre_Post;
    bool uFlag = instruction.upBit;
    bool lFlag = instruction.storeBit;
    uint32_t rn = instruction.rn; //base register
    uint32_t rd = instruction.rd;  //source/destination register
    uint32_t offset = instruction.offsets_or_operand2;

//    uint32_t address;

    //Offset is immediate offset or shifted register
    if  (iFlag) {
        uint32_t *result = 0;
        uint32_t *carryBit = 0;
        getValFromRegisterOp2(offset, result, carryBit, state);
        offset = *result;
//        //offset is shifted register
//        uint32_t shift;
//        uint32_t rm = get_n_bits(offset, 0, 4);
//        uint32_t rmContent = state->registers[rm];
//        uint32_t intOrReg = get_n_bits(offset, 4, 1);
//        uint32_t shiftType = get_n_bits(offset, 5, 2);
//
//        if (intOrReg) {
//            //shift specified by constant amount
//            shift = get_n_bits(offset, 7, 5);
//        }
//        else {
//            //shift specified by register rs
//            uint32_t rs = get_n_bits(offset, 8, 4);
//            uint32_t rsContent = state->registers[rs];
//            //should be last byte of rs, is it it though??? :
//            shift = get_n_bits(rsContent, 0, 8);
//            //could also be get_n_bits(rsContent, 24, 8); ???
//        }
//
//        rmContent = state->registers[rm];
//        offset = shiftRegister(rmContent, shift, shiftType);
    }

    //decides whether to add or subtract the offset
//    if (!uFlag) {
//        offset = - offset;
//    }

    //Uses post or pre indexing
//    if (pFlag) {
//        //add/subtract offset from base register before transferring data
//        //pre-indexing
//        // should not change base register
////        address = state->registers[rn] + offset;
//        if (uFlag) {
//            address = state->registers[rn] + offset;
//        } else {
//            address = state->registers[rn] - offset;
//
//        }
//    } else {
//        //add/subtract offset from base register after transferring data
//        //post-indexing
//        //changes base register
//        address = state->registers[rn];
//        if (uFlag) {
//            state->registers[rn] = address + offset;
//        } else {
//            state->registers[rn] = address - offset;
//        }
//
//    }
//
//

    uint32_t data = 0;
    if (pFlag) {
        if (uFlag) {
            data = state->registers[rn] + offset;
        } else {
            data = state->registers[rn] - offset;
        }
    } else {
        if (uFlag) {
            state->registers[rn] += offset;
        } else {
            state->registers[rn] -= offset;
        }
        data = state->registers[rn];
    }

    if (data > numOfAddresses || data < minAddress) {
        printf("Error: Out of bounds memory access at address 0x%08x\n", data);
    } else {
        //Loads word from memory or stores word to memory
        if (lFlag) {
            //word loaded from memory
            state->registers[rd] = *((uint32_t * )(state->mem + data));
        } else {
            //word stored into memory
            *((uint32_t * )(state->mem + data)) = state->registers[rd];
        }
    }

}


