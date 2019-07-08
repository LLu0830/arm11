//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../emulator_utility/state.h"
#include "decode.h"


#include "../emulator_utility/utility.h"
#include "../emulator_utility/instruction.h"
#include "../emulator_utility/DefinedTypes.h"
#include "../execute/execute.h"
//Add decode function
//add ARM11.registers.decoded=output



Instruction decode(uint32_t fetched) {

    //what type of Instruction it is..
    //store the Instruction in corresponding Instruction
    //and execute
    //initialize Instruction and return it

    Instruction initialisedInstruction = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Instruction *instruction = &initialisedInstruction;

    instruction->conditionType = get_n_bits(fetched, 28, 4);

    //HLT
    if (fetched == 0) {
        return decodeHLT(instruction, fetched);
    }

    //BR
    uint32_t branchCheck = get_n_bits(fetched, 27, 1);
    if (branchCheck != 0) {
        return decodeBR(instruction, fetched);
    }

    //SDT
    uint32_t SDTCheck = get_n_bits(fetched, 26, 1);
    if (SDTCheck != 0) {
        return decodeSDT(instruction, fetched);
    }


    //MUL & DP
    uint32_t bit4Check = get_n_bits(fetched, 4, 1);
    if (!bit4Check) {
        return decodeDP(instruction, fetched);
    } else {
        uint32_t i = get_n_bits(fetched, 25, 1);
        if (i) {
            return decodeDP(instruction, fetched);
        } else {
            uint32_t bit7Check = get_n_bits(fetched, 7, 1);
            if (!bit7Check) {
                return decodeDP(instruction, fetched);
            } else {
                return decodeMUL(instruction, fetched);
            }
        }
    }
}


Instruction decodeMUL(Instruction *instruction, uint32_t fetched) {
    instruction->instructionType = MUL;
// holds the A bit
    instruction->accumulate = get_n_bits(fetched, 21, 1);
// holds the S bit
    instruction->S = get_n_bits(fetched, 20, 1);
// rd,rn,rs,rm  should be 4-bit addresses in the array registers, 0-12
    instruction->rd = get_n_bits(fetched, 16, 4);
    instruction->rn = get_n_bits(fetched, 12, 4);
    instruction->rs = get_n_bits(fetched, 8, 4);
    instruction->rm = get_n_bits(fetched, 0, 4);

    return *instruction;
}


Instruction decodeDP(Instruction *instruction, uint32_t fetched) {
    instruction->instructionType = DP;
//    holds the I bit
    instruction->I = get_n_bits(fetched, 25, 1);
//    holds opCOde
    instruction->operationType = get_n_bits(fetched, 21, 4);
//    holds the S bit
    instruction->S = get_n_bits(fetched, 20, 1);
// rn,rd should be 4-bit addresses in the array registers, 0-12
    instruction->rn = get_n_bits(fetched, 16, 4);
    instruction->rd = get_n_bits(fetched, 12, 4);
//    holds the 8-bit operand2
    instruction->offsets_or_operand2 = get_n_bits(fetched, 0, 12);

    return *instruction;

}

Instruction decodeSDT(Instruction *instruction, uint32_t fetched) {
    instruction->instructionType = SDT;
    //    holds the I bit
    instruction->immediateOffset = get_n_bits(fetched, 25, 1);
    //    holds the P bit
    instruction->Pre_Post = get_n_bits(fetched, 24, 1);
    //    holds the U bit
    instruction->upBit = get_n_bits(fetched, 23, 1);
    //    holds the L bit
    instruction->L = get_n_bits(fetched, 20, 1);
    // rn,rd should be 4-bit addresses in the array registers, 0-12
    instruction->rn = get_n_bits(fetched, 16, 4); //base register
    instruction->rd = get_n_bits(fetched, 12, 4);  //source/destination register
    //    holds the 12-bit offset
    instruction->offsets_or_operand2 = get_n_bits(fetched, 0, 12);

    return *instruction;


}


Instruction decodeBR(Instruction *instruction, uint32_t fetched) {
    instruction->instructionType = BR;
//  holds the 24-bit offset
    instruction->offsets_or_operand2 = get_n_bits(fetched, 0, 24);

    return *instruction;

}

Instruction decodeHLT(Instruction *instruction, uint32_t fetched) {
    instruction->instructionType = HLT;

    return *instruction;

}
