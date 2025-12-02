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

// void save_to_file(const Token *token_buffer, size_t token_buffer_length)
// {
//     printf(":: file open entry\n");
//     FILE *fptr = fopen("output_map.txt", "w");
//     if (fptr == NULL)
//     {
//         error_handler("Failed to save, file could not be opened");
//         return;
//     }
//     printf(":: file exists?\n");
//     char *format_string = malloc(256 * sizeof(char));
//     if (format_string == NULL) {
//         error_handler("failed to allocate memory for formatted string");
//         fclose(fptr);
//         free(format_string);
//         return;
//     }
//     // for (int j = 0; j < token_buffer_length; ++j)
//     // {
//     //     printf("%d element\n", j);
//     //     snprintf(format_string, 255, "COUNT=%d\nVALUE=%s\nKEY=%s\nKIND=%s", j, token_buffer[j].value, token_buffer[j].key, get_token_kind(token_buffer[j].tokenKind));
//     //     fprintf(fptr, "%s\n", format_string);
//     // }
//     char* stringTest = "hello world";
//     fprintf(fptr, "%s", stringTest);
//     fclose(fptr);
//     free(format_string);
//     return;
// }

void save_to_file(const Token *token_buffer, size_t token_buffer_length)
{
    printf(":: file open entry\n");

    // Open file for writing (w+ would create if not exists)
    FILE *fptr = fopen("output_map.txt", "w+");
    if (fptr == NULL)
    {
        error_handler("Failed to save, file could not be opened");
        return;
    }
    char* format_string = "hello world";
    printf(":: file exists? fptr: %p\n", (void *)fptr);
    size_t written = fprintf(fptr, "%s", format_string);
    if (written == 0)
    {
        printf(":: No bytes written to file. Check fptr integrity.\n");
        fclose(fptr);
        // free(format_string);
        return;
    }
    printf(":: written %zu bytes to file\n", written);
    fclose(fptr); // Close after write
    // free(format_string);
    return;
}
