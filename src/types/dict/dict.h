#pragma once

#include "../../../include.h"

// Dict Types
typedef struct jd_dict_entry {
    char* key;
    jd_value val;
} jd_dict_entry;

typedef struct jd_dict {
    jd_dict_entry *entries;
    int len;
    int cap;
} jd_dict;

// Helpers
void jd_dict_print(jd_dict *dict, int max);

// Constructors
jd_dict *jd_dict_new(int size);

// Methods
jd_value* jd_dict_get(jd_dict *dict, char* key);
int jd_dict_set(jd_dict *dict, jd_dict_entry *entry);

// Destructors
int jd_dict_delete(jd_dict *dict, char* key);
void jd_dict_free(jd_dict *dict);