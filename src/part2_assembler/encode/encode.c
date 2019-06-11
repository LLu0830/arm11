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


void encode(assembler_instruction *instruction) {
    printf("start encode\n");


    token mnemonic = instruction->mnemonic;
    char snd = *(mnemonic + 1);
    switch (*mnemonic) {
        case 't':
            if (snd == 's') {
                instruction->type = DP;
                instruction->operationType = tst;
            } else {
                instruction->type = DP;
                instruction->operationType = teq;
            }
            break;
        case 'b':
            instruction->type = BR;
            switch (snd) {
                case 'e':
                    instruction->operationType = beq;
                    break;
                case 'n':
                    instruction->operationType = bne;
                    break;
                case 'g':
                    if (*(mnemonic + 2) == 'e') {
                        instruction->operationType = bge;
                    } else {
                        instruction->operationType = bgt;
                    }
                    break;
                case 'l':
                    if (*(mnemonic + 2) == 'e') {
                        instruction->operationType = ble;
                    } else {
                        instruction->operationType = blt;
                    }
                    break;
                default:
                    instruction->operationType = b;
                    break;
            }
            break;
        case 'm':
            printf("in encode, case m\n");
            if (snd == 'o') {
                instruction->type = DP;
                instruction->operationType = mov;
            } else {
                instruction->type = MUL;
                if (snd == 'u') {
                    instruction->operationType = mul;
                } else {
                    instruction->operationType = mla;
                }
            }
            break;
        case 'l':
            if (snd == 's') {
                instruction->type = SPECIAL;
                instruction->operationType = lsl;
            } else {
                instruction->type = SDT;
                instruction->operationType = ldr;
            }
            break;
        case 'a':
            if (snd == 'd') {
                instruction->type = DP;
                instruction->operationType = add;
            } else {
                if (*(mnemonic + 3) == 'e') {
                    instruction->type = SPECIAL;
                    instruction->operationType = andeq;
                } else {
                    instruction->type = DP;
                    instruction->operationType = and;
                }
            }
            break;
        case 's':
            if (snd == 'u') {
                instruction->operationType = sub;
                instruction->type = DP;
            } else {
                instruction->type = SDT;
                instruction->operationType = str;
            }
            break;
        case 'e':
            instruction->operationType = eor;
            break;
        case 'o':
            instruction->operationType = orr;
            break;
        case 'r':
            instruction->operationType = rsb;
            break;
        case 'c':
            instruction->operationType = cmp;
            break;

        default:
            break;

    }


    switch (instruction->type) {
        case DP:
            printf("in DP\n");
            encodeDP(instruction);
            break;
        case MUL:
            encodeMUL(instruction);
            break;
        case SDT:
            encodeSDT(instruction);
            break;
        case BR:
            encodeBR(instruction);
            break;
        case SPECIAL:
            encodeSPECIAL(instruction);
            break;
        default:
            break;
    }
}
