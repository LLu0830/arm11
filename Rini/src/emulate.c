#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t Word;

int main(int argc, char **argv) {
    FILE *fp;
    Word *mem = calloc(16384, sizeof(Word));
    fp = fopen(argv[0], "rb");
    while (!feof(fp)) {
        fread(mem, sizeof(Word), 1, fp);
    }
    return EXIT_SUCCESS;
}


