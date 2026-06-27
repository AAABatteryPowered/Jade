#include "../../../include.h"

int jd_array_push(jd_array *array, jd_value *entry) {
    return jd_array_insert(array, array->len, entry);
}

void jd_array_pop(jd_array *array) {
    if (array->len > 0) {
        array->len--;
    }
}

int jd_array_insert(jd_array *array, int index, jd_value *entry) {
    if (index < 0 || index > array->len) {
        return -1;
    }

    if (array->cap == 0) array->cap = 8;

    if (array->len == array->cap) {
        array->cap *= 2;
        jd_value *tmp = realloc(array->entries, array->cap * sizeof(jd_value));
        if (tmp == NULL) return -1;
        array->entries = tmp;
    }
    
    memmove(&array->entries[index+1], &array->entries[index], (array->len - index) * sizeof(jd_value));
    array->entries[index] = *entry;
    array->len++;

    return 0;
}

int jd_array_delete(jd_array *array, int index) {
    if (index < 0 || index >= array->len) return -1;

    memmove(&array->entries[index],
            &array->entries[index + 1],
            (array->len - index - 1) * sizeof(jd_value));

    array->len--;

    return 0;
}

jd_value* jd_array_get(jd_array *array, int index) {
    if (index < 0 || index >= array->len) return NULL;
    return &array->entries[index];
}

void jd_array_set(jd_array *array, int index, jd_value *entry) {
    array->entries[index] = *entry;
}

int jd_array_index(jd_array *array, jd_value* value) {
    for (int i=0; i < array->len; i++) {
        if (cmp(&array->entries[i], value) == 0) {
            return i;
        }
    }

    return -1;
}

void jd_array_free(jd_array *array) {
    free(array->entries);
    free(array);
}