//
// Created by mw6118 on 11/06/19.
//

#include <bits/types/FILE.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define max 100

void prints(FILE *file) {
    printf("start!!");

    uint32_t *buffer = malloc(sizeof(uint32_t));


    for (int curr = 0; curr < max; curr = curr + 4) {
        if (!feof(file)) {
            fread(buffer, sizeof(uint32_t), 1, file);
            printf("%08x: %08x\n", curr, *buffer);
        } else {
            return;
        }
    }

    free(buffer);
}
