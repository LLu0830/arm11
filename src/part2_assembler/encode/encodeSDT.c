//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "encodeSDT.h"
#include "encodeDP.h"
#include "../assembler_utility/table.h"
#include "../../part1_emulator/emulator_utility/utility.h"
#include "../assembler_utility/assembler_utility.h"

#define MAX_MOV 0xFF
#define COND_POSITION 28U
#define BIT_VALUE_1_POSITION 26U
#define I_BIT_POSITION 25U
#define P_BIT_POSITION 24U
#define U_BIT_POSITION 23U
#define L_BIT_POSITION 20U
#define RN_POSITION 16U
#define RD_POSITION 12U
#define OFFSET_POSITION 0U
#define PIPELINE_OFFSET 2


void set_I_bit(assembler_instruction* instruction, uint32_t *I_bit) {
    if (instruction->arg3[0] == '#') {
        *I_bit = 0;
    }
//shifted register
    else if (instruction->arg3[0] == 'r') {
        *I_bit = 1;
    } else {
        perror("Wrong input");
        exit(EXIT_FAILURE);
    }
}


//helper function to concatenate all the parts of an SDT instruction
uint32_t concatSDT(uint32_t cond, uint32_t bit_value_1, uint32_t I_bit, uint32_t P_bit, uint32_t U_bit,
        uint32_t L_bit, uint32_t rn, uint32_t rd, uint32_t offset){
    cond = shiftLeft(cond, COND_POSITION);
    bit_value_1 = shiftLeft(bit_value_1, BIT_VALUE_1_POSITION);
    I_bit = shiftLeft(I_bit, I_BIT_POSITION);
    P_bit = shiftLeft(P_bit, P_BIT_POSITION);
    U_bit = shiftLeft(U_bit, U_BIT_POSITION);
    L_bit = shiftLeft(L_bit, L_BIT_POSITION);
    rn = shiftLeft(rn, RN_POSITION);
    rd = shiftLeft(rd, RD_POSITION);
    offset = shiftLeft(offset, OFFSET_POSITION);

    return cond | bit_value_1 | I_bit | P_bit | U_bit | L_bit | rn | rd | offset;
}

void put_in_array(uint32_t expression) {
    instruction_array[array_counter] = expression;
    array_counter++;

}

//encodes Single Data Transfer instructions
void encodeSDT(assembler_instruction *instruction){

    //all parts of a SDT instruction
    uint32_t cond = 14;         //always condition code: 1110
    uint32_t bit_value_1 = 1;   //1
    uint32_t I_bit = 1;             //shifted register/immediate offset flag
    uint32_t P_bit = 0;             //pre-indexing flag
    uint32_t U_bit = 1;         //add/subtract flag (upbit)
    uint32_t L_bit = 0;             //load/store flag
    uint32_t rn = 0;                //base register
    uint32_t rd = 0;                //destination register
    uint32_t offset = 0;            //offset of register


    //load or store differentiation
    //<ldr/str>
    if (instruction->operationType == ldr) {
        L_bit = 1;
    }
    else if (instruction->operationType == str) {
        L_bit = 0;
    }
    else {
        perror("Invalid operation type");
        exit(EXIT_FAILURE);
    }


    //setting destination register Rd
    rd = getValue(instruction->arg1);

    //general loading case
    //address has form <=expression>

    if (L_bit && ((instruction->arg2[0] == '='))) {

        //pre-indexing
        P_bit = 1;
        I_bit = 0;
        rn = 15;
        //offset = 0;
        //interpreting as a mov instruction
        if (getValue(instruction->arg2)<MAX_MOV){

            free(instruction->mnemonic);

            instruction->operationType = mov;

            instruction->mnemonic = copy_string("mov");

            instruction->arg2[0] = '#';

            instruction->type = DP;
            encodeDP(instruction);

            return;
        }
        //not interpreting as a mov instruction
        else{
            offset = numOfAddress - instruction->currentAddress - PIPELINE_OFFSET;
            offset = 4 * offset;
            numOfAddress++;
            U_bit = 1;
            put_in_array(getValue(instruction->arg2));
        }

    }
    else if (instruction->arg2[0] == '[') {
        rn = getValue(instruction->arg2+1);
        U_bit = 1;

        if ((instruction->arg2[3] == ']') || (instruction->arg2[4] == ']')) {

            //rn is a register with offset 0
            //[Rn]
            //pre-indexing
            if(instruction->arg3 == NULL){
                P_bit = 1;
                I_bit = 0;
                offset = 0;
            }
                //[Rn]<#expression>
            //post-indexing, offset not zero
            else {
                P_bit = 0;
                offset = getValue(instruction->arg3);
                //immediate value
                set_I_bit(instruction, &I_bit);
            }

        }
        //[Rn, <#expression>]
        //pre-indexing, offset not 0
        else {
            P_bit = 1;
            offset = getValue(instruction->arg3);
            set_I_bit(instruction, &I_bit);
        }

    } else {
        printf("failure \n");
        exit(EXIT_FAILURE);
    }

    if ((int32_t) offset < 0) {
        offset = -offset;
        U_bit = 0;
    }

    //puts encoded SDT instruction to instruction->encoded
    //I_bit, P_bit, rn, offset have been initialized at some point
    instruction->encoded = concatSDT(cond, bit_value_1, I_bit, P_bit, U_bit, L_bit, rn, rd, offset);
}
