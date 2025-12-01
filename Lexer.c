#include <stdio.h>
#include <stdlib.h>

#include "Token.h"
#include "Lexer.h"
#include "String/String.h"
#include "Error.h"
#include "DataStructures/BinaryTree.h"

void loop_tokens(Token *token_buffer, size_t buffer_length)
{
    printf(":: loop entry\n");
    for (int i = 0; i < buffer_length; ++i)
    {
        printf("COUNT=%d\nVALUE=%s\nKEY=%s\nKIND=%c\n", i, token_buffer[i].value, token_buffer[i].key, token_buffer[i].tokenKind);
    }
}

Token *lexer_analysis(char *buffer)
{
    size_t buffer_length = stringLength(buffer);
    Token* token_buffer = (Token* )malloc(sizeof(Token) * buffer_length);
    // TEMP
    char *value_buffer = (char *)malloc(sizeof(char) * 256);
    char *key_buffer = (char *)malloc(sizeof(char) * 256);

    bool quotes_opened = false;
    int independent_count = 0;

    if (buffer_length < 0) {
        error_handler("Error reading buffer");
        return NULL;
    }
    for (int i = 0; i < buffer_length; ++i) {
        printf("at char %d -> ", i+1);
        Token token_stream;
        TokenKind kind = get_char_to_token_kind(buffer[i]);
        // Create binary tree after colon key
        // Perform recursive parsing
        if (kind == OPEN_CLOSED_QUOTES)
        {
            quotes_opened = !quotes_opened;
            goto value_entry;
        }
        if (quotes_opened) {
            value_buffer[independent_count] = buffer[i];
            independent_count++;
            goto value_entry;
        }
        if (kind == COLON)
        {
            struct BinaryTree *head_tree = (struct BinaryTree *)malloc(sizeof(struct BinaryTree) * 1);
            sprintf(head_tree->root, "%c\n", kind);
            head_tree->right = NULL;
            size_t length = getStringLength(value_buffer);
            value_buffer[length-1] = '\0';
            Add_Root_To_Tree(&head_tree, value_buffer, value_buffer);
            independent_count = 0;
        }
        value_entry:
        token_stream.tokenKind = kind;
        token_stream.value = "value_test";
        token_stream.key = get_token_kind(kind);
        token_buffer[i] = token_stream;
    }
    free(value_buffer);
    free(key_buffer);
    return token_buffer;
}
