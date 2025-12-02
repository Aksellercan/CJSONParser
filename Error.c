#include <stdio.h>

#include "Error.h"
#include "String/String.h"

signed long save_error_to_file(const char *error_line)
{
    FILE *fptr = fopen("error.log", "a");
    if (fptr == NULL)
    {
        printf("Error opening error log file");
        return -1;
    }
    size_t written = fprintf(fptr, "%s\n", error_line);
    if (written == 0)
    {
        fclose(fptr);
        return -1;
    }
    fclose(fptr);
    return written;
}

// save to file error lines
void *error_handler(char *error_string)
{
    printf("%s\n", error_string);
    save_error_to_file(error_string);
    return NULL;
}