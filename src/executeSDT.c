//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "executeSDT.h"
#include "state.h"
#include "utility.h"


void executeSDT(struct registers ARM11_registers, uint32_t b) {

    int i = get_n_bits(b, 25, 1);
    int p = get_n_bits(b, 24, 1);
    int u = get_n_bits(b, 23, 1);
    int l = get_n_bits(b, 20, 1);
    int rn = get_n_bits(b, 16, 4); //base register
    int rd = get_n_bits(b, 12, 4);  //source/destination register
    int offset = get_n_bits(b, 0, 12);

    if  (i == 1) {
        //offset is shifted register
    }
    else {
        //offset is unsigned 12 bit immediate offset
    }

    if (p == 1) {
        //add/substract offset from base register before transferring data
        // should not change base register
    }
    else {
        //add/substract offset from base register after transferring data
        //changes base register
    }

    if (u == 1) {
        //add offset to the base register
    }
    else {
        //substract offset from the base register
    }

    if (l == 1) {
        //word loaded from memory
    }
    else {
        //word stored into memory
    }

}