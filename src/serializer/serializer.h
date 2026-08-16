#pragma once

#include "../../include.h"

size_t get_ser_val_size(jd_value *val);
size_t get_ser_arr_size(jd_value *val);
size_t get_ser_dict_size(jd_value *val);

char *serialize_value(jd_value value);

char *serialize_dictionary();

char *serialize_array(jd_array array);