#pragma once

#include "../../include.h"

static jd_value parse_token(TokenList *tokens, int *current);
static jd_array parse_array(TokenList *tokens, int *current);
static jd_dict parse_dict(TokenList *tokens, int *current);

static Token next_token(TokenList *tokens, int *current);

void parse_tokens(TokenList *tokens);