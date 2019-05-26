//
// Created by Katarina Kulkova on 25.05.2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "registers.h"
#include "memory.h"
#include "binaryFileLoader.h"
#include "utility.h"

void binaryFileLoader(int argc, char **argv) {
    FILE *fp;
    fp = fopen(argv[0], "rb");
    while (!feof(fp)) {
        fread(mem, size32, 1, fp);
    }
}