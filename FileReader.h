#ifndef FILEREADER_H
#define FILEREADER_H

#include <stdbool.h>

#include "Token.h"

char* read_file();
void save_to_file(const Token *token_buffer, size_t token_buffer_length);

#endif
