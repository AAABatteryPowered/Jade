#pragma once

#include "../../include.h"

char *serialize_value(jd_value value);

char *serialize_dictionary();

char *serialize_array(jd_array array);

void serialize_string(char *string);