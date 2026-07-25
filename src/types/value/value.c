#include "../../../include.h"

void jd_value_print(jd_value *value) {
    switch (value->type) {
    case JD_INT:
        printf("%d", value->v_int);
        break;

    case JD_FLOAT:
        printf("%f", value->v_float);
        break;

    case JD_STRING:
        printf("\"%s\"", value->v_string);
        break;

    case JD_BOOL:
        printf(value->v_bool ? "true" : "false");
        break;

    case JD_NULL:
        printf("null");
        break;

    case JD_ARRAY:
        jd_array_print(value->v_array, -1);
        break;

    case JD_DICT:
        jd_dict_print(value->v_dict, -1);
        break;

    default:
        printf("<unknown>");
        break;
    }
    printf("\n");
}