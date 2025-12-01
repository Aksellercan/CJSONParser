#ifndef LEXER_H
#define LEXER_H

Token *lexer_analysis(char *buffer);
void loop_tokens(Token *token_buffer, size_t buffer_length);

#endif