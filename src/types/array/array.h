#pragma once

#include "../../../include.h"

// Array Types
typedef struct jd_array {
    jd_value *entries;
    int len;
    int cap;
} jd_array;

// Helpers
int jd_array_index(jd_array *array, int value);

// Constructors
jd_array jd_array_new(int size);

// Methods
int jd_array_push(jd_array *array, jd_value *entry);
int jd_array_insert(jd_array *array, int index, jd_value *entry);

void jd_array_pop(jd_array *array);
int jd_array_delete(jd_array *array, int index);

jd_value* jd_array_get(jd_array *array, int index);
int jd_array_set(jd_array *array, int index, jd_value *entry);

// Destructors

void jd_array_free(jd_array *array);