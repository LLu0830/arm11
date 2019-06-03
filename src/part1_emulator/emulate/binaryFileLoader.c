//
// Created by Katarina Kulkova on 25.05.2019.
//

#include "../emulator_utility/state.h"
#include "binaryFileLoader.h"
#include <stdlib.h>
#include <stdio.h>

//binary file loader
uint8_t *binaryFileLoader(char **argv) {
    int size8 = sizeof(uint8_t);
    uint8_t *mem = calloc(numOfAddresses, size8);
    FILE *fp;

//    Opens the binary file specified as a command line argument
    fp = fopen(argv[1], "rb");
    if (ferror(fp)) {
        perror("Error reading from binary file.\n");
    }

//    Reads from the file into mem as long as the file is non-empty
    while (!feof(fp)) {
        fread(mem, numOfAddresses, 1, fp);
    }

//    File closed once reading is finished
    fclose(fp);

    return mem;
}
