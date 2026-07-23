#pragma once

#include "../../include.h"
#include "../token/token.h"

typedef struct Parser {
    TokenList *tokens;
} Parser;

void parser_init(Lexer *lexer, TokenList *tokens);
void parser_parse(Parser *parser);