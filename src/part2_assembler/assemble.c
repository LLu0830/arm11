#include <stdlib.h>
#include "../part2_assembler/readLabels/readLabels.h"
#include "../part2_assembler/readInstruction/readInstruction.h"
#include "../part2_assembler/encode/encode.h"
#include "../part2_assembler/assembler_utility/table.h"
#include "assembler_utility/prints.h"
#include "../part2_assembler/assembler_utility/assembler_utility.h"

int main(int argc, char **argv) {
//  File pointers for reading from (fpr) and writing to (fpw)
    FILE *fp_read;
    FILE *fp_write;
    fp_read = fopen(argv[1], "r");
    fp_write = fopen(argv[2], "wb+");
    label_address_list table = {NULL, NULL};
    readLabels(&table, fp_read);
    fclose(fp_read);
//    only have this for now for Katarina's readInstruction function below - may be removed later
    int counter = 0;
    fp_read = fopen(argv[1], "r");
//    not sure on what to put as the loop condition
    while (1) {
        assembler_instruction *instruction = calloc(1, sizeof(assembler_instruction));
        if (!readInstruction(fp_read, &counter, instruction)) {
            break;
        }
        encode(instruction);
        fwrite(&instruction->encoded, sizeof(uint32_t), 1, fp_write);
        instruction_free(instruction);
    }


    fclose(fp_write);
    fclose(fp_read);
//    not sure how to implement this - depends on Katarina's readInstruction function
    return EXIT_SUCCESS;
}
