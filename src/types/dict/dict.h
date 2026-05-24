#include "include.h"

#pragma once

#define jd_dict() {malloc(8 * sizeof(jd_dict_entry)), 0, 8}

// Dict Methods
jd_value* jd_dict_lookup(jd_dict *dict, char* key);