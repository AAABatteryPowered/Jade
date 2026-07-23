#include "../../include.h"

void lexer_init(Lexer *lexer, char *json_string) {
    lexer->src = json_string;
    lexer->pos = 0;
    lexer->line = 0;
    lexer->column = 0;
}

void lexer_from_file(Lexer *lexer, char *filepath) {
    FILE *file_pointer = fopen(filepath, "r");

    if (file_pointer == NULL) {
        fclose(file_pointer);
        return;
    }

    fseek(file_pointer, 0, SEEK_END);
    size_t file_size = ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);

    char *buffer = malloc(file_size + 1);
    
    if (buffer == NULL) {
        fclose(file_pointer);
        return;
    }

    size_t total_len = 0;

    fread(buffer, 1, file_size, file_pointer);

    buffer[file_size] = '\0';

    lexer->src = buffer;

    fclose(file_pointer);
}

TokenList lexer_tokenise(Lexer *lexer, const size_t max_tokens) {
    size_t len = strlen(lexer->src);
    Token *tokens = malloc(sizeof(Token) * max_tokens);
    size_t tokens_len = 0;

    //return (TokenList){0,0};

    while (lexer->pos < len) {
        char current = lexer->src[lexer->pos];

        if (current == '{') {
            tokens[tokens_len++] = (Token){TOKEN_LBRACE, NULL};
        } else if (current == '}') {
            tokens[tokens_len++] = (Token){TOKEN_RBRACE, NULL};
        } else if (current == '[') {
            tokens[tokens_len++] = (Token){TOKEN_LBRACKET, NULL};
        } else if (current == ']') {
            tokens[tokens_len++] = (Token){TOKEN_RBRACKET, NULL};
        } else if (current == ':') {
            tokens[tokens_len++] = (Token){TOKEN_COLON, NULL};
        } else if (current == ',') {
            tokens[tokens_len++] = (Token){TOKEN_COMMA, NULL};
        } else if (current == '"') {
            lexer->pos++;
            current = lexer->src[lexer->pos];
            char* reading = malloc(1024);;
            size_t reading_len = 0;

            while (current != '"') {
                reading[reading_len++] = current;
                lexer->pos++;
                current = lexer->src[lexer->pos];
            }

            reading[reading_len] = '\0';

            tokens[tokens_len++] = (Token){TOKEN_STRING, reading};
            lexer->pos++;
            
            continue;
        } else if (isdigit((unsigned char)current) || current == '-') {
            char* reading = malloc(1024);;
            size_t reading_len = 0;

            while (isdigit((unsigned char)current) || current == '-' || current == '+' || current == '.' || current == 'e') {
                reading[reading_len++] = current;
                lexer->pos++;
                current = lexer->src[lexer->pos];
            }

            char *end;
            strtod(reading, &end);
            if (*end == '\0') {
                tokens[tokens_len++] = (Token){TOKEN_NUMBER, reading};
            } else {
                tokens[tokens_len++] = (Token){TOKEN_ERROR, "Invalid Number"};
            }
            
            continue;
        } else if (isalpha(current)) {
            char *word = malloc(6);
            size_t num_len = 0;

            while (isalpha(current)) {
                word[num_len] = current;
                num_len++;

                lexer->pos++;
                current = lexer->src[lexer->pos];
            }

            word[num_len] = '\0';

            if (strcmp(word, "true") == 0) {
                tokens[tokens_len++] = (Token){TOKEN_TRUE, word};
            } else if (strcmp(word, "false") == 0) {
                tokens[tokens_len++] = (Token){TOKEN_FALSE, word};
            } else if (strcmp(word, "null") == 0) {
                tokens[tokens_len++] = (Token){TOKEN_NULL, word};
            }

            continue;
        } else if (isspace(current)) {
            
        }

        lexer->pos++;
    }
    
    tokens[tokens_len++] = (Token){TOKEN_EOF, NULL};

    TokenList returning = (TokenList){tokens, tokens_len};

    return returning;
}