//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "assembler_utility.h"

//
// Created by Katarina Kulkova on 02.06.2019.
//

#include <stdlib.h>
#include "assembler_utility.h"

int lines_in_file(char *file_name) {
    int lines = 0;
    char ch;
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error in opening source file");
        exit(EXIT_FAILURE);
    }
    bool on_new_line = true;
    while ((ch = getc(file)) != EOF) {
        if (ch == '\n') {
            if (!on_new_line) {
                lines++;
            }
            on_new_line = true;
        } else {
            on_new_line = false;
        }
    }
    fclose(file);
    return lines;
}


char **load_source_file(char *load_filename, int lines) {
    FILE *file = fopen(load_filename, "r");
    if (file == NULL) {
        perror("Error in opening source file");
        exit(EXIT_FAILURE);
    }

    //Set up the correct size array;
    char **loaded_file = create_2d_array(lines, MAX_LINE_LENGTH);

    // Try to read the file line by line
    int size = 0;
    while (size < lines && fgets(loaded_file[size], MAX_LINE_LENGTH, file)) {
        // Strips any trailing newlinesword_size
        if (loaded_file[size][0] != '\n' && loaded_file[size][0] != '\r') {
            loaded_file[size][strcspn(loaded_file[size], "\n")] = 0;
            size++;
        }
    }
    fclose(file);
    return loaded_file;
}

//saves array of words to a file, could be used in binary writer
void save_file(uint_8 *data, char *file_name, int file_size) {
    FILE *file = fopen(file_name, "wb");
    if (file == NULL) {
        perror("Error in opening save file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < file_size; i++) {
        fwrite(&data[i], sizeof(word_t), 1, file);
    }

    fclose(file);
}

//string_arrays_t *make_string_arrays(void) {
//    string_arrays_t *string_arrays = malloc(sizeof(string_arrays_t));
//    if (!string_arrays) {
//        perror("Unable to allocate memory for string arrays");
//        exit(EXIT_FAILURE);
//    }
//    string_arrays->max_elements = INITIAL_ARRAY_SIZE;
//    string_arrays->arrays = malloc(string_arrays->max_elements
//                                   * sizeof(string_array_t *));
//    if (!string_arrays->arrays) {
//        perror("Unable to allocate memory for string arrays");
//        exit(EXIT_FAILURE);
//    }
//    string_arrays->size = 0;
//    return string_arrays;
//}
//
///**
// * @brief Adds an array to a string_arrays_t.
// *
// * If more memory is required it doubles the array size.
// * @param string_arrays The string_arrays_t to add the array to.
// * @param array The array to add to the string_arrays.
// */
//void add_string_arrays(string_arrays_t *string_arrays, string_array_t *array) {
//    if (string_arrays->size >= string_arrays->max_elements) {
//        string_arrays->max_elements *= 2;
//        string_arrays->arrays = realloc(string_arrays->arrays,
//                                        string_arrays->max_elements
//                                        * sizeof(string_array_t *));
//        if (!string_arrays->arrays) {
//            perror("Unable to expand size of string arrays");
//            exit(EXIT_FAILURE);
//        }
//    }
//    string_arrays->arrays[string_arrays->size] = array;
//    string_arrays->size++;
//}
//
///**
// * @brief Frees all memory used in a string_arrays_t.
// *
// * @param string_arrays The string_arrays to free.
// */
//void free_string_arrays(string_arrays_t *string_arrays) {
//    for (int i = 0; i < string_arrays->size; i++) {
//        for (int j = 1; j < string_arrays->arrays[i]->size; j++) {
//            free(string_arrays->arrays[i]->array[j]);
//        }
//        free(string_arrays->arrays[i]->array);
//        free(string_arrays->arrays[i]);
//    }
//    free(string_arrays->arrays);
//    free(string_arrays);
//}