#pragma once

#include "../../include.h"

// JD Value

typedef enum {
    JD_INT,
    JD_FLOAT,
    JD_STRING,
    JD_BOOL,
    JD_NULL,
    JD_ARRAY,
    JD_DICT,
} jd_type;

typedef struct jd_array jd_array;

typedef struct jd_value {
    jd_type type;
    union {
        int    v_int;
        float  v_float;
        char  *v_string;
        bool   v_bool;
        jd_array *v_array;
    };
} jd_value;