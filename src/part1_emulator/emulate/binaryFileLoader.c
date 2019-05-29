//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "part1_emulator/emulator_utility/state.h"
#include "binaryFileLoader.h"
#include "part1_emulator/emulator_utility/utility.h"
#include <math.h>

//Add binary file loader - we already did that, so just copy it here??
// (Rini) done

uint8_t * binaryFileLoader(char **argv) {
    int size8 = sizeof(uint8_t);
    uint8_t *mem = calloc(65536, size8);
    FILE *fp;
    fp = fopen(argv[0], "rb");
    while (!feof(fp)) {
        fread(mem, size8, 1, fp);
    }
    return mem;
}