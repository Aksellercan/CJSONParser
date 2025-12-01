#include <stdbool.h>
#include <stdio.h>

#include "Error.h"
#include "Token.h"

TokenKind get_char_to_token_kind(char token_char)
{
    switch (token_char)
    {
    case OPEN_BRACKET:
        /* code */
        printf("OPEN_BRACKET %d\n", OPEN_BRACKET);
        return OPEN_BRACKET;
    case CLOSE_BRACKET:
        /* code */
        printf("CLOSE_BRACKET %d\n", CLOSE_BRACKET);
        return CLOSE_BRACKET;
    case OPEN_CURLY:
        /* code */
        printf("OPEN_CURLY %d\n", OPEN_CURLY);
        return OPEN_CURLY;
    case CLOSED_CURLY:
        /* code */
        printf("CLOSED_CURLY %d\n", CLOSED_CURLY);
        return CLOSED_CURLY;
    case OPEN_PARAN:
        /* code */
        printf("OPEN_PARAN %d\n", OPEN_PARAN);
        return OPEN_PARAN;
    case CLOSED_PARAN:
        /* code */
        printf("CLOSED_PARAN %d\n", CLOSED_PARAN);
        return CLOSED_PARAN;
    case OPEN_CLOSED_QUOTES:
        /* code */
        printf("OPEN_CLOSED_QUOTES %d\n", OPEN_CLOSED_QUOTES);
        return OPEN_CLOSED_QUOTES;
    case OPEN_CLOSED_SINGLE_QUOTES:
        /* code */
        printf("OPEN_CLOSED_SINGLE_QUOTES %d\n", OPEN_CLOSED_SINGLE_QUOTES);
        return OPEN_CLOSED_SINGLE_QUOTES;
    case COLON:
        /* code */
        printf("COLON %d\n", COLON);
        return COLON;
    case SEMI_COLON:
        /* code */
        printf("SEMI COLON %d\n", SEMI_COLON);
        return SEMI_COLON;
    case SPACE:
        /* code */
        printf("SPACE %d\n", SPACE);
        return SPACE;
    case NEW_LINE:
        /* code */
        printf("NEW LINE %d\n", NEW_LINE);
        return NEW_LINE;
    case TERMINATION:
        /* code */
        printf("TERMINATION %d\n", TERMINATION);
        return TERMINATION;
    case COMMA:
        printf("COMMA %d\n", COMMA);
        return COMMA;
    default:
        error_handler("either Key or Value");
        return KEY;
    }
}

bool is_token_key_or_value(TokenKind token_kind)
{
    if (token_kind != VALUE || token_kind != KEY)
    {
        return false;
    }
    return true;
    // return token_kind != VALUE || token_kind != KEY;
}

char* get_token_kind(TokenKind token_kind)
{
    switch (token_kind)
    {
    case OPEN_BRACKET:
        /* code */
        printf("OPEN_BRACKET %d\n", OPEN_BRACKET);
        return "OPEN_BRACKET";
    case CLOSE_BRACKET:
        /* code */
        printf("CLOSE_BRACKET %d\n", CLOSE_BRACKET);
        return "CLOSE_BRACKET";
    case OPEN_CURLY:
        /* code */
        printf("OPEN_CURLY %d\n", OPEN_CURLY);
        return "OPEN_CURLY";
    case CLOSED_CURLY:
        /* code */
        printf("CLOSED_CURLY %d\n", CLOSED_CURLY);
        return "CLOSED_CURLY";
    case OPEN_PARAN:
        /* code */
        printf("OPEN_PARAN %d\n", OPEN_PARAN);
        return "OPEN_PARAN";
    case CLOSED_PARAN:
        /* code */
        printf("CLOSED_PARAN %d\n", CLOSED_PARAN);
        return "CLOSED_PARAN";
    case OPEN_CLOSED_QUOTES:
        /* code */
        printf("OPEN_CLOSED_QUOTES %d\n", OPEN_CLOSED_QUOTES);
        return "OPEN_CLOSED_QUOTES";
    case OPEN_CLOSED_SINGLE_QUOTES:
        /* code */
        printf("OPEN_CLOSED_SINGLE_QUOTES %d\n", OPEN_CLOSED_SINGLE_QUOTES);
        return "OPEN_CLOSED_SINGLE_QUOTES";
    case COLON:
        /* code */
        printf("COLON %d\n", COLON);
        return "COLON";
    case SEMI_COLON:
        /* code */
        printf("SEMI COLON %d\n", COLON);
        return "SEMI_COLON";
    case SPACE:
        /* code */
        printf("SPACE %d\n", COLON);
        return "SPACE";
    case NEW_LINE:
        /* code */
        printf("NEW LINE %d\n", COLON);
        return "NEW_LINE";
    case TERMINATION:
        /* code */
        printf("TERMINATION %d\n", COLON);
        return "TERMINATION";
    case COMMA:
        /* code */
        printf("COMMA %d\n", COMMA);
        return "COMMA";
    default:
        error_handler("either Key or Value");
        return "KEY";
    }
}