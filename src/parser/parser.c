#include "../../include.h"

const char *token_type_names[] = {
    "{",
    "}",
    "[",
    "]",
    ":",
    ",",
    "STRING",
    "NUMBER",
    "TRUE",
    "FALSE",
    "NULL",
    "EOF"
};

static Token next_token(TokenList *tokens, int *current) {
    (*current)++;
    return tokens->tokens[*current];
} 

static jd_value parse_token(TokenList *tokens, int *current) {
    Token token = tokens->tokens[*current];
    jd_value node;

    switch (token.type) {
    case TOKEN_LBRACE:
        node = (jd_value){JD_DICT};
        node.v_dict = parse_dict(tokens, current);
        break;
    case TOKEN_LBRACKET:
        node = (jd_value){JD_ARRAY};
        node.v_array = parse_array(tokens, current);
        break;
    case TOKEN_STRING:
        node = (jd_value){JD_STRING};
        node.v_string = token.value;
        break;
    case TOKEN_NUMBER:
        node = (jd_value){JD_INT};
        node.v_int = atoi(token.value);
        break;
    case TOKEN_TRUE:
        node = (jd_value){JD_BOOL};
        node.v_bool = true;
        break;
    case TOKEN_FALSE:
        node = (jd_value){JD_BOOL};
        node.v_bool = false;
        break;
    case TOKEN_NULL:
        node = (jd_value){};
        break;
    default:
        break;
    }

    return node;
}

static jd_array *parse_array(TokenList *tokens, int *current) {
    jd_array *array = jd_array_new(8); 
    Token current_token = next_token(tokens, current);

    while (current_token.type != TOKEN_RBRACKET) {
        jd_value value = parse_token(tokens, current);
        jd_array_append(array, &value);
        current_token = next_token(tokens, current);
        if (current_token.type == TOKEN_COMMA) { current_token = next_token(tokens, current); }
    }

    return array;
}

static jd_dict *parse_dict(TokenList *tokens, int *current) {
    jd_dict *dict = jd_dict_new(8);
    Token current_token = next_token(tokens, current);
    //printf("dict time\n");

    while (current_token.type != TOKEN_RBRACE) {
        if (current_token.type == TOKEN_STRING) {
            char *key = current_token.value;
            current_token = next_token(tokens, current);

            if (current_token.type != TOKEN_COLON) {
                printf("Failed to parse dictionary: Comma expected, found '%s'", token_type_names[current_token.type]);
                return dict;
            }

            next_token(tokens, current);

            jd_value value = parse_token(tokens, current);
            jd_dict_set(dict, &(jd_dict_entry){key, value});
            //printf("%d\n", dict.len);
        }

        current_token = next_token(tokens, current);
        if (current_token.type == TOKEN_COMMA) { current_token = next_token(tokens, current); }
    }

    return dict;
}

jd_value parse_tokens(TokenList *tokens) {
    int current = 0;
    jd_value full_node = parse_token(tokens, &current);

    return full_node;
    //THE SEGFAULT IS IN DICT PRINT I REPEAT THE SEGFAULT IS IN JD_dict_print
    
} 