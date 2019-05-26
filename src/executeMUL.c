//
// Created by MANSHU WANG on 5/24/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>


#include "registers.h"
#include "memory.h"
#include "executeMUL.h"
#include "utility.h"
#include "multiplyInstruction/DefinedTypes.h"

void executeMUL(struct registers ARM11_registers, uint32_t fetched) {
// check if condition field is satisfied

// get cond 4bits
    uint32_t mask = 0xf << 28;

    fetched &= mask;

    fetched >> 28;



//    switch (b) {
//        case 0000:
//            break;
//        case 0001:
//            break;
//        case 1010:
//            break;
//        case 1011:
//            break;
//
//    }


// holds the A bit
    bool abit = 0x1 & fetched >> 21;

// holds the S bit
    bool sbit = 0x1 & fetched >> 20;

// rd,rn,rs,rm it should be a 4-bits address, I'm not sure about the type..
    register_address rd = fetched >> 16 & 0xf;

    register_address rn = fetched >> 12 & 0xf;

    register_address rs = fetched >> 8 & 0xf;

    register_address rm = fetched & 0xf;
    
    
    
    
    
    
    
    uint32_t result;
    
    if (abit){
        //Accumulate is set, performs a multiply and accumulate
        
    } else {
        // performs only multiply
        
        
    }
    
    
    
    
    
    




}

