#include "include.h"

// Functionality:
// Parse from files
// Parse from *char
// Data Type and Good way of representing in C
// Error Handling (return error object)
// Serializing to *char
// Fetch value (without having to parse entire object)
// Freeing and Ownership idk
// Merging json objects and their representations in c, adding to existing json *char strings

// JSON is obviously JSON, Jade is parsed JSON




char* serialize_jade();




int main() {
    jd_dict objects = jd_dict(2);
    objects.entries = (jd_dict_entry[]){{"hi", 4}, {"bye", 2}};


    jd_dict mydict = parse_json("jnsfgjnsfgbkjfngbkjnfg");
    
    return 0;
}