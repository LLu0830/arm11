//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "part1_emulator/emulator_utility/state.h"
#include "binaryFileLoader.h"
#include "part1_emulator/emulator_utility/utility.h"
#include <math.h>


<<<<<<< HEAD
//binary file loader
uint32_t * binaryFileLoader(char **argv) {
    int size8 = sizeof(uint8_t);
    uint8_t *mem = calloc(numOfAddresses, size8);
=======
uint8_t * binaryFileLoader(char **argv) {
    int size8 = sizeof(uint8_t);
    uint8_t *mem = calloc(65536, size8);
>>>>>>> 84651c74bdb066eed4db975fabe2d5e7824acc9d
    FILE *fp;
    fp = fopen(argv[0], "rb");
    while (!feof(fp)) {
        fread(mem, size8, 1, fp);
    }
    return mem;
}