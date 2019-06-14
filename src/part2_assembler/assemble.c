#include <stdlib.h>
#include <assert.h>
#include "../part2_assembler/readLabels/readLabels.h"
#include "../part2_assembler/readInstruction/readInstruction.h"
#include "../part2_assembler/encode/encode.h"
#include "../part2_assembler/assembler_utility/table.h"
#include "../part2_assembler/assembler_utility/assembler_utility.h"

uint32_t instruction_array[10];
int array_counter = 0;

int main(int argc, char **argv) {
//  File pointers for reading from (fpr) and writing to (fpw)
    FILE *fp_read;
    FILE *fp_write;
    fp_read = fopen(argv[1], "r");
    fp_write = fopen(argv[2], "wb");
    label_address_list *table = initialize_list();
    readLabels(table, fp_read);
    fclose(fp_read);
    int counter = 0;
    fp_read = fopen(argv[1], "r");

    while (1) {
        assembler_instruction *instruction = calloc(1, sizeof(assembler_instruction));
        if (!readInstruction(fp_read, &counter, instruction)) {
            break;
        }
        if (instruction->currentAddress != -1) {
            encode(instruction, table);
            assert(fp_write != 0);
            fwrite(&instruction->encoded, sizeof(uint32_t), 1, fp_write);
            instruction_free(instruction);
        }
    }

    for (int i = 0; i < array_counter; i++){
        fwrite(&instruction_array[i], sizeof(uint32_t), 1, fp_write);
    }

    fclose(fp_write);
    fclose(fp_read);
    return EXIT_SUCCESS;
}
