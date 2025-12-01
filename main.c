#include <stdio.h>

#include "FileReader.h"
#include "Lexer.h"
#include "Error.h"
#include "String/String.h"

int main() {
    printf("hello world\n");
    printf("prod\n");
    char* file_buffer = read_file();
    if (file_buffer == NULL) {
        error_handler("Failed to initialize file buffer");
        return 1;
    }
    Token *token_buffer = lexer_analysis(file_buffer);
    size_t buffer_length = stringLength(file_buffer);
    loop_tokens(token_buffer, buffer_length);
    save_to_file(token_buffer, buffer_length);
    return 0;
}