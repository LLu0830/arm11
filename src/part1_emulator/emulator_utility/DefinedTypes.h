//
// Created by MANSHU WANG on 5/24/2019.
//
#include <stdint.h>

#ifndef C_GROUP_31_TYPES_H
#define C_GROUP_31_TYPES_H

//opCodes supported by emulator (with mnemonics)

typedef enum {
    AND = 0x0,
    EOR = 0x1,
    SUB = 0x2,
    RSB = 0x3,
    ADD = 0x4,
    TST = 0x8,
    TEQ = 0x9,
    CMP = 0xa,
    ORR = 0xc,
    MOV = 0xd,
    mul,
    MLA,
    LDR,
    STR,
    BEQ,
    BNE,
    BGE,
    BLT,
    BGT,
    BLE,
    B,
    lsl,
    ANDEQ
} OpCode;


// Types of instruction
typedef enum {
    DP,
    MUL,
    SDT,
    BR,
    HLT,
    SPECIAL,

} InstructionType;


//Condition
typedef enum {
    EQ = 0x0,
    NE = 0x1,
    GE = 0xA,
    LT = 0xB,
    GT = 0xC,
    LE = 0xD,
    AL = 0xE
} Cond;

//Shift types
typedef enum{
    LSL = 0,
    LSR = 1,
    ASR = 2,
    ROR = 3
} ShiftType;

//CPSR flags
typedef enum {

    //last result negative
            N = 0x8,

    //last result zero
            Z = 0x4,

    //caused a bit to be carried out
            C = 0x2,

    //last result overflowed
            V = 0x0

} CPSR_helper;

typedef uint8_t register_address;


#endif //C_GROUP_31_INSTRUCTION_H

