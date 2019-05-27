//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "registers.h"
#include "memory.h"
#include "binaryFileLoader.h"
#include "utility.h"
#include <math.h>

//Add binary file loader - we already did that, so just copy it here??
// (Rini) done

uint32_t * binaryFileLoader(char **argv) {
    int size32 = sizeof(uint32_t);
    uint32_t *mem = calloc((pow(2, 16) / size32), size32);
    FILE *fp;
    fp = fopen(argv[0], "rb");
    while (!feof(fp)) {
        fread(mem, size32, 1, fp);
    }
    return mem;
}