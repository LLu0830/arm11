//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "executeSDT.h"
#include "state.h"
#include "utility.h"


uint32_t loadFrom(uint32_t address);
void storeTo(uint32_t address);

void executeSDT(struct stateOfMachine ARM11_registers, uint32_t fetched) {

    uint32_t iFlag = get_n_bits(fetched, 25, 1);
    uint32_t pFlag = get_n_bits(fetched, 24, 1);
    uint32_t uFlag = get_n_bits(fetched, 23, 1);
    uint32_t lFlag = get_n_bits(fetched, 20, 1);
    uint32_t rn = get_n_bits(fetched, 16, 4); //base register
    uint32_t rd = get_n_bits(fetched, 12, 4);  //source/destination register
    uint32_t offset = get_n_bits(fetched, 0, 12);

    uint32_t address;

    //Offset is immediate offset or shifted register
    if  (iFlag == 1) {
        //offset is shifted register
        uint32_t shift;
        uint32_t rm = get_n_bits(offset, 0, 4);
        uint32_t rmContent = ARM11_registers.registers[rm];
        uint32_t intOrReg = get_n_bits(offset, 4, 1);
        uint32_t shiftType = get_n_bits(offset, 5, 2);

        if (intOrReg == 0) {
            //shift specified by constant amount
            shift = get_n_bits(offset, 7, 5);
        }
        else {
            //shift specified by register rs
            uint32_t rs = get_n_bits(offset, 8, 4);
            uint32_t rsContent = ARM11_registers.registers[rs];
            //should be last byte of rs, is it it though??? :
            shift = get_n_bits(rsContent, 0, 8);
            //could also be get_n_bits(rsContent, 24, 8); ???
        }

        rmContent = ARM11_registers.registers[rm];
        //TO DO: shiftRegister function
        offset = shiftRegister(rmContent, shift, shiftType);
    }
    else {
        //unsigned 12 bit immediate offset
        offset = offset;

        //I guess this else is not needed, but I am keeping it just in case
        // I don't understand the spec that well
    }

//    if (uFlag == 1) {
//        //add offset to the base register
//    }
//    else {
//        //substract offset from the base register
//        offset = negate(offset);
//    }

    if (uFlag == 0) {
        offset = - offset;
    }

    //Uses post or pre indexing
    if (pFlag == 1) {
        //add/substract offset from base register before transferring data
        //pre-indexing
        // should not change base register
        address = ARM11_registers.registers[rn] + offset;
    }
    else {
        //add/substract offset from base register after transferring data
        //post-indexing
        //changes base register
        address = ARM11_registers.registers[rn];
        ARM11_registers.registers[rn] = address + offset;
    }


    //Loads word from memory or stores word to memory
    if (lFlag == 1) {
        //word loaded from memory
        return loadFrom(address, rd);
    }

    else {
        //word stored into memory
        uint32_t rdContent = ARM11_registers.registers[rd];
        storeTo(address, rdContent)
    }

}

//loads word from address in memory to registers
uint32_t loadFrom(uint32_t address, uint32_t destination) {
    uint32_t word = stateOfMachine.mem[address];
    ARM11_registers.registers[destination] = word;
}

//stores word to address in memory
void storeTo(uint32_t address, uint32_t word) {
    ARM11_registers.mem[address] = word;
}

