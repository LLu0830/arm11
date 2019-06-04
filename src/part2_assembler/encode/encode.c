//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "encode.h"
#include "encodeDP.h"
#include "encodeMUL.h"
#include "encodeSDT.h"
#include "encodeBR.h"



void encode(instruction *instruction) {
    switch (instruction.type) {
        case DP:
            encodeDP(instruction);
        case MUL:
            encodeMUL(instruction);
        case SDT:
            encodeSDT(instruction);
        case BR:
            encodeBR(instruction);
        case SPECIAL:
            encodeSPECIAL(instruction);
    }
}
