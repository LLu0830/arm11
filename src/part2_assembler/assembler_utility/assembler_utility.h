//
// Created by Katarina Kulkova on 02.06.2019.
//

#ifndef SRC_ASSEMBLER_UTILITY_H
#define SRC_ASSEMBLER_UTILITY_H

#include <stdint.h>

void set_4_bits(uint32_t *b, int pos, uint32_t val);
int lines_in_file(char *file_name);
char **load_source_file(char *load_filename, int lines);
void save_file(uint8_t *data, char *file_name, int file_size);
#endif //SRC_ASSEMBLER_UTILITY_H
