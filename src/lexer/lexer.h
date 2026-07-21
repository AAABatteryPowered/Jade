#pragma once

#include "../../include.h"
#include "../token/token.h"

typedef struct Lexer {
    const char *src;
    int line, column, pos;
} Lexer;

void lexer_init(Lexer *lexer, char *json_string);
void lexer_from_file(Lexer *lexer, char *filepath);
TokenList lexer_tokenise(Lexer *lexer, const size_t max_tokens);