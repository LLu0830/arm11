//
// Created by Katarina Kulkova on 25.05.2019.
//

#include "../emulator_utility/state.h"
#include "binaryFileLoader.h"
#include <stdlib.h>
#include <stdio.h>

//binary file loader
uint8_t * binaryFileLoader(char **argv) {
    int size8 = sizeof(uint8_t);
    uint8_t *mem = calloc(numOfAddresses, size8);
    FILE *fp;
    fp = fopen(argv[1], "rb");
    while (!feof(fp)) {
        fread(mem, size8, 1, fp);


    }
    uint32_t *mem_p = (uint32_t *) mem;
    printf("%x\n", *mem_p);

    return mem;
}
