#include "../../../include.h"

// Static Helpers

static inline int next_power_of_2(int x)
{
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x + 1;
}

// Helpers

int jd_array_index(jd_array *array, jd_value* value) {
    for (int i=0; i < array->len; i++) {
        if ((&array->entries[i]) == value) {
            return i;
        }
    }

    return -1;
}

void jd_array_print(jd_array *array, int max) {
    printf("[jade] Length: %d\n[jade] Cap: %d\n", array->len, array->cap);

    if (max > array->len || max == -1) {
        max = array->len;
    }

    for (int i=0; i < max; i++) {
        printf("[jade] [%d] -> ", i);
        jd_value_print(&(array->entries[i]));
    }
    
    int remaining = array->len - max;
    if (remaining > 0) {
        printf("%d Entries Remain Unprinted\n", remaining);
    }
}

// Constructors

jd_array *jd_array_new(int size) {
    jd_array *array = malloc(sizeof(jd_array));

    if (array == NULL) return NULL;

    array->cap = next_power_of_2(size);
    array->entries = malloc(array->cap * sizeof(jd_value));

    if (array->entries == NULL) return NULL;

    array->len = 0;
    
    return array;
}

// Methods

int jd_array_append(jd_array *array, jd_value *entry) {
    return jd_array_insert(array, array->len, entry);
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

void jd_array_pop(jd_array *array) {
    if (array->len > 0) {
        array->len--;
    }
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

// Destructors

void jd_array_free(jd_array *array) {
    free(array->entries);
    free(array);
}