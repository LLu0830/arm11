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



instruction_type decode(uint32_t fetched) {

    //what type of instruction it is..
    //store the instruction in corresponding instruction
    //and execute
    //initialize instruction_type and return it

//    struct stateOfMachine state = *stateP;

    instruction_type initialisedInstruction = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    instruction_type *instruction = &initialisedInstruction;

    instruction->conditionType = get_n_bits(fetched, 28, 4);

    //HLT
    if (fetched == 0) {
        printf("type HLT in decoding\n");
        return decodeHLT(instruction, fetched);
    }

    //BR
    uint32_t branchCheck = get_n_bits(fetched, 27, 1);
    if (branchCheck != 0) {
        printf("type BR in decoding\n");
        return decodeBR(instruction, fetched);
    }

    //SDT
    uint32_t SDTCheck = get_n_bits(fetched, 26, 1);
    if (SDTCheck != 0) {
        printf("type SDT in decoding\n");
        return decodeSDT(instruction, fetched);
    }


    //MUL & DP
    uint32_t bit4Check = get_n_bits(fetched, 4, 1);
    if (!bit4Check) {
        printf("type DP in decoding\n");
        return decodeDP(instruction, fetched);
    } else {
        uint32_t i = get_n_bits(fetched, 25, 1);
        if (i) {
            printf("type DP in decoding\n");
            return decodeDP(instruction, fetched);
        } else {
            uint32_t bit7Check = get_n_bits(fetched, 7, 1);
            if (!bit7Check) {
                printf("type DP in decoding\n");
                return decodeDP(instruction, fetched);
            } else {
                printf("type MUL in decoding\n");
                return decodeMUL(instruction, fetched);
            }
        }
    }
}



instruction_type decodeMUL(instruction_type *instruction, uint32_t fetched) {
    instruction->instructionType = MUL;
// holds the A bit
    instruction->accumulate = get_n_bits(fetched, 21, 1);
// holds the S bit
    instruction->scc = get_n_bits(fetched, 20, 1);
// rd,rn,rs,rm it should be a 4-bits address in the array registers, 0-12
    instruction->rd = get_n_bits(fetched, 16, 4);
    instruction->rn = get_n_bits(fetched, 12, 4);
    instruction->rs = get_n_bits(fetched, 8, 4);
    instruction->rm = get_n_bits(fetched, 0, 4);

    return *instruction;
}


instruction_type decodeDP(instruction_type *instruction, uint32_t b) {
    instruction->instructionType = DP;
    instruction->conditionType = get_n_bits(b, 28, 4);
    instruction->immediateOperand = get_n_bits(b, 25, 1);
    instruction->operationType = get_n_bits(b, 21, 4);
    instruction->scc = get_n_bits(b, 20, 1);
    instruction->rn = get_n_bits(b, 16, 4);
    instruction->rd = get_n_bits(b, 12, 4);
    instruction->offsets_or_operand2 = get_n_bits(b, 0, 12);

    return *instruction;

}

instruction_type decodeSDT(instruction_type *instruction, uint32_t fetched) {
    instruction->instructionType = SDT;
    instruction->immediateOffset = get_n_bits(fetched, 25, 1);
    instruction->Pre_Post = get_n_bits(fetched, 24, 1);
    instruction->upBit = get_n_bits(fetched, 23, 1);
    instruction->storeBit = get_n_bits(fetched, 20, 1);
    instruction->rn = get_n_bits(fetched, 16, 4); //base register
    instruction->rd = get_n_bits(fetched, 12, 4);  //source/destination register
    instruction->offsets_or_operand2 = get_n_bits(fetched, 0, 12);
    return *instruction;


}


instruction_type decodeBR(instruction_type *instruction, uint32_t b) {
    instruction->instructionType = BR;
    instruction->offsets_or_operand2 = get_n_bits(b, 0, 23);
    return *instruction;

}

instruction_type decodeHLT(instruction_type *instruction, uint32_t fetched) {
    instruction->instructionType = HLT;
    printf("Ins Type: %x\n", instruction->instructionType);
    return *instruction;

}
