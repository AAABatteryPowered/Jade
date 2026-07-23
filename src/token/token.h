#pragma once

#include "../../include.h"

typedef enum {
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_LBRACKET,
    TOKEN_RBRACKET,
    TOKEN_COLON,
    TOKEN_COMMA,

    TOKEN_STRING,
    TOKEN_NUMBER,

    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_NULL,
    
    TOKEN_EOF,
    TOKEN_ERROR,
} Token_type;

extern const char *token_type_names[];

typedef struct Token {
    Token_type type;
    char *value;
} Token;

typedef struct TokenList {
    Token *tokens;
    size_t tokens_len;
} TokenList;