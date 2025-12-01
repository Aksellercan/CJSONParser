#ifndef TOKEN_H
#define TOKEN_H

#include <stdbool.h>

// TOKEN KIND
typedef enum
{
    // VALUE/KEY

    // VALUE
    VALUE = false,
    // KEY
    KEY = true,

    // PARANTHESIS

    // []
    CLOSE_BRACKET = ']',
    OPEN_BRACKET = '[',
    //{}
    OPEN_CURLY = '{',
    CLOSED_CURLY = '}',

    //()
    OPEN_PARAN = '(',
    CLOSED_PARAN = ')',

    // SYMBOLS
    //""
    OPEN_CLOSED_QUOTES = '"',
    //''
    OPEN_CLOSED_SINGLE_QUOTES = '\'',
    //:
    COLON = ':',
    //;
    SEMI_COLON = ';',
    //,
    COMMA = ',',

    // FORMATTERS

    // SPACE
    SPACE = ' ',
    // NEWLINE
    NEW_LINE = '\n',
    // TERMINATE
    TERMINATION = '\0'
} TokenKind;

// DATA STRUCT
typedef struct
{
    char *key;
    char *value;
    TokenKind tokenKind;
} Token;

TokenKind get_char_to_token_kind(char token_char);
bool is_token_key_or_value(TokenKind token_kind);
char *get_token_kind(TokenKind token_kind);

#endif