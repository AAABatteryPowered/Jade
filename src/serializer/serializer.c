#include "../../include.h"

size_t get_ser_val_size(jd_value *val) {}

size_t get_ser_arr_size(jd_value *val) {}

size_t get_ser_dict_size(jd_value *val) {}

char *serialize_value(jd_value value) {
    char *returning = NULL;

    switch (value.type)
    {
    case JD_INT:
        sprintf(returning, "%i", value.v_int);
        break;

    case JD_FLOAT:
        sprintf(returning, "%f", value.v_float);
        break;

    case JD_STRING:
        returning = value.v_string;
        break;

    case JD_BOOL:
        if (value.v_bool) {
            returning = "true";
        } else {
            returning = "false";
        }
        break;

    case JD_NULL:
        returning = "null";
    }

    return returning;
}

char *serialize_dictionary(jd_dict dict) {
    char* serialized_dict = malloc(256);
    if (serialized_dict == NULL) return NULL;
    serialized_dict[0] = '{';
    serialized_dict[1] = '\0';

    for (int i=0; i<dict.len; i++) {
        jd_dict_entry entry = dict.entries[i];
        char *key = entry.key;
        char *serialized_value = serialize_value(entry.val);
        strcat(serialized_dict, key);
        strcat(serialized_dict, ":");
        strcat(serialized_dict, serialized_value);

        if (i+1 < dict.len) strcat(serialized_dict, ",");
    }

    strcat(serialized_dict, "}");

    return serialized_dict;
}

char *serialize_array(jd_array array) {
    char *serialized_children = malloc(256);
    if (serialized_children == NULL) return NULL;
    serialized_children[0] = '[';

    for (int i=0; i<array.len; i++) {
        char *serialized = serialize_value(array.entries[i]);
        //printf("%i", i);
        strcat(serialized_children, serialized);
        if (i+1 < array.len) strcat(serialized_children, ",");
    }

    strcat(serialized_children, "]");

    return serialized_children;
}