#include "../../../include.h"

int jd_array_push(jd_array *array, jd_value *entry) {

}

void jd_array_pop(jd_array *array) {

}

int jd_array_insert(jd_array *array, int index, jd_value *entry) {

}

void jd_array_delete(jd_array *array, int index) {

}

jd_value* jd_array_get(jd_array *array, int index) {
    return &array->entries[index];
}

void jd_array_set(jd_array *array, int index, jd_value *entry) {
    array->entries[index] = *entry;
}

int jd_array_index(jd_array *array, jd_value* value) {
    for (int i=0; i < array->len; i++) {
        if (strcmp(array->entries[i], *value) == 0) {
            return i;
        }
    }

    return -1;
}
int jd_array_contains(jd_array *array, int value);

void jd_array_free(jd_array *array) {
    free(array->entries);
    free(array)
}