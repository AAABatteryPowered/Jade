#pragma once

typedef struct Lexer {
    const char *src;
    int line, column, pos;
} Lexer;