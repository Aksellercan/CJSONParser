#include <stdio.h>

#include "Error.h"
#include "String/String.h"

void save_error_to_file(const char *error_line)
{
    printf(":: file open entry\n");

    // Open file for writing (w+ would create if not exists)
    FILE *fptr = fopen("error.log", "a");
    if (fptr == NULL)
    {
        error_handler("Failed to save, file could not be opened");
        return;
    }
    size_t written = fprintf(fptr, "%s\n", error_line);
    if (written == 0)
    {
        printf(":: No bytes written to file. Check fptr integrity.\n");
        fclose(fptr);
        return;
    }
    printf(":: written %zu bytes to file\n", written);
    fclose(fptr);
    return;
}

// save to file error lines
void *error_handler(char *error_string)
{
    //snprintf(error_string, stringLength(error_string),"%s\n");
    save_error_to_file(error_string);
    return NULL;
}