#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef _WIN32
#include <direct.h>
#define OS_SEP "\\"
#else
#include <sys/stat.h>
#define OS_SEP "/"
#endif

#include "Error.h"
#include "Token.h"

char* read_file() {
    FILE *fptr = fopen("parse.json", "r");
    if (fptr == NULL)
    {
        error_handler("Failed to read the file");
        return NULL;
    }
    // get file length
    fseek(fptr, 0, SEEK_END);
    const int filesize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    char *buffer = malloc(filesize * sizeof(char));
    if (buffer == NULL)
    {
        free(buffer);
        fclose(fptr);
        error_handler("Failed to create buffer");
        return NULL;
    }
    fread(buffer, sizeof(char), filesize, fptr);
    fclose(fptr);
    printf("DEBUG\n");
    printf("%s\n", buffer);
    return buffer;
}

signed int save_to_file(const Token *token_buffer, size_t token_buffer_length)
{
    FILE *fptr = fopen("output_map.txt", "w+");
    if (fptr == NULL)
    {
        error_handler("Failed to save, file could not be opened");
        return -1;
    }
    char *format_string = malloc(64 * sizeof(char));
    if (format_string == NULL) {
        error_handler("failed to allocate memory for formatted string");
        fclose(fptr);
        free(format_string);
        return -1;
    }
    for (int j = 0; j < token_buffer_length; ++j)
    {
        snprintf(format_string, 64, "COUNT=%d\nVALUE=%s\nKEY=%s", j, token_buffer[j].value, token_buffer[j].key);
        fprintf(fptr, "%s\n", format_string);
    }
    fclose(fptr);
    free(format_string);
    return 0;
}
