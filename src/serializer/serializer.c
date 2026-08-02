#include "../../include.h"

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

char *serialize_dictionary() {
    
}

char *serialize_array(jd_array array) {
    char *serialized_children = malloc(256);
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

void serialize_string(char *string) {

}