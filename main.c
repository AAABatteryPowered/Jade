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
    jd_dict objects = jd_dict_new(8);

    for (int i=0;i<100;i++) {
        char *key = malloc(6);
        sprintf(key, "key%d", i);

        jd_dict_entry entry = (jd_dict_entry){key, (jd_value){JD_INT, i}};

        jd_dict_set(&objects, &entry);
    }

    jd_dict_print(&objects, 100);

    return 0;
}

/*jd_dict_set(objects,
        &(jd_dict_entry){"hi", &(jd_value){JD_INT, 5}}
    );       

    
    if (fetched == NULL) {
        return;
    }
    

    jd_dict_delete(objects, "hi");
     
    //jd_dict_set(&objects, &(jd_dict_entry){"hi", 5})
    //jd_value myvalue = {JD_INT, 5};
    //objects.entries = (jd_dict_entry[]){{"hi", &myvalue}};

    //jd_dict mydict = parse_json("jnsfgjnsfgbkjfngbkjnfg");
    
    return 0;*/