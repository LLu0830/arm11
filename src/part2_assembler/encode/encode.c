//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "encode.h"
#include "encodeDP.h"
#include "encodeMUL.h"
#include "encodeSDT.h"
#include "encodeBR.h"
#include "encodeSPECIAL.h"
#include "../assembler_utility/table.h"


void encode(assembler_instruction *instruction, label_address_list *table) {


    token mnemonic = instruction->mnemonic;
    char snd = *(mnemonic + 1);
    switch (*mnemonic) {
        case 't':
            if (snd == 's') {
                instruction->type = DP;
                instruction->operationType = TST;
            } else {
                instruction->type = DP;
                instruction->operationType = TEQ;
            }
            break;
        case 'b':
            instruction->type = BR;
            switch (snd) {
                case 'e':
                    instruction->operationType = BEQ;
                    break;
                case 'n':
                    instruction->operationType = BNE;
                    break;
                case 'g':
                    if (*(mnemonic + 2) == 'e') {
                        instruction->operationType = BGE;
                    } else {
                        instruction->operationType = BGT;
                    }
                    break;
                case 'l':
                    if (*(mnemonic + 2) == 'e') {
                        instruction->operationType = BLE;
                    } else {
                        instruction->operationType = BLT;
                    }
                    break;
                default:
                    instruction->operationType = B;
                    break;
            }
            break;
        case 'm':
            if (snd == 'o') {
                instruction->type = DP;
                instruction->operationType = MOV;
            } else {
                instruction->type = MUL;
                if (snd == 'u') {
                    instruction->operationType = mul;
                } else {
                    instruction->operationType = MLA;
                }
            }
            break;
        case 'l':
            if (snd == 's') {
                instruction->type = SPECIAL;
                instruction->operationType = lsl;
            } else {
                instruction->type = SDT;
                instruction->operationType = LDR;
            }
            break;
        case 'a':
            if (snd == 'd') {
                instruction->type = DP;
                instruction->operationType = ADD;
            } else {
                if (*(mnemonic + 3) == 'e') {
                    instruction->type = SPECIAL;
                    instruction->operationType = ANDEQ;
                } else {
                    instruction->type = DP;
                    instruction->operationType = AND;
                }
            }
            break;
        case 's':
            if (snd == 'u') {
                instruction->operationType = SUB;
                instruction->type = DP;
            } else {
                instruction->type = SDT;
                instruction->operationType = STR;
            }
            break;
        case 'e':
            instruction->type = DP;
            instruction->operationType = EOR;
            break;
        case 'o':
            instruction->type = DP;
            instruction->operationType = ORR;
            break;
        case 'r':
            instruction->type = DP;
            instruction->operationType = RSB;
            break;
        case 'c':
            instruction->type = DP;
            instruction->operationType = CMP;
            break;

        default:
            break;

    }


    switch (instruction->type) {
        case DP:
            encodeDP(instruction);
            break;
        case MUL:
            encodeMUL(instruction);
            break;
        case SDT:
            encodeSDT(instruction);
            break;
        case BR:
            encodeBR(instruction, table);
            break;
        case SPECIAL:
            encodeSPECIAL(instruction, table);
            break;
        default:
            break;
    }
}
