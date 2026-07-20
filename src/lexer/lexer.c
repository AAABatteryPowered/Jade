#include "../../../include.h"

void lexer_init(Lexer *lexer,char *json_string, const size_t max_tokens) {
    size_t len = strlen(json_string);
    Token *tokens = malloc(sizeof(Token) * max_tokens);
    size_t tokens_len = 0;

    while (lexer->pos < len) {
        char current = json_string[lexer->pos];

        if (current == '{') {
            tokens[tokens_len] = (Token){TOKEN_LBRACE, NULL};
            tokens_len++;
            lexer->pos++;
            continue;
        } else if (current == '}') {
            tokens[tokens_len] = (Token){TOKEN_RBRACE, NULL};
            tokens_len++;
            lexer->pos++;
            continue;
        } else if (current == '[') {
            tokens[tokens_len] = (Token){TOKEN_LBRACKET, NULL};
            tokens_len++;
            lexer->pos++;
            continue;
        } else if (current == ']') {
            tokens[tokens_len] = (Token){TOKEN_RBRACKET, NULL};
            tokens_len++;
            lexer->pos++;
            continue;
        } else if (current == ':') {
            tokens[tokens_len] = (Token){TOKEN_COLON, NULL};
            tokens_len++;
            lexer->pos++;
            continue;
        } else if (current == ',') {
            tokens[tokens_len] = (Token){TOKEN_COMMA, NULL};
            tokens_len++;
            lexer->pos++;
            continue;
        } else if (current == '"') {
            lexer->pos++;
            char* reading = malloc(1024);;
            size_t reading_len = 0;

            while (current != '"') {
                current = json_string[lexer->pos];
                reading[reading_len] = current;
                reading_len++;
                lexer->pos++;
            }

            lexer->pos++;

            tokens[tokens_len] = (Token){TOKEN_STRING, reading};
            tokens_len++;
            
            continue;
        }

        lexer->pos++;
    }
}