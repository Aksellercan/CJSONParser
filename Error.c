#include <stdio.h>

#include "Error.h"


void *error_handler(char *error_string)
{
    printf("%s\n", error_string);
    return NULL;
}