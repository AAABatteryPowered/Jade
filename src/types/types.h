#pragma once

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

typedef struct jd_value {
    jd_type type;
    union {
        int    v_int;
        float  v_float;
        char  *v_string;
        bool   v_bool;
    };
} jd_value;

// JD Dict

typedef struct jd_dict_entry {
    char* key;
    jd_value* val;
} jd_dict_entry;

typedef struct jd_dict {
    jd_dict_entry *entries;
    int len;
    int cap;
} jd_dict;