#include "include.h"

jd_value* jd_dict_lookup(jd_dict *dict, char* key) {
    for (int i=0; i < dict->len; i++) {
        if (strcmp(dict->entries[i].key, key) == 0) {
            return &dict->entries[i].val;
        }
    }
}

int jd_dict_insert(jd_dict *dict, jd_dict_entry *entry) {
    if ((dict->len) == dict->cap) {
        dict->cap *= 2;
        jd_dict_entry *tmp = realloc(dict->entries, dict->cap * sizeof(jd_dict_entry));
        if (tmp == NULL) return -1;
        dict->entries = tmp;
    }
    dict->entries[dict->len] = *entry;
    dict->len++;
    return 0;
}

static int jd_dict_index(jd_dict *dict, char *key) {
    for (int i = 0; i < dict->len; i++) {
        if (strcmp(dict->entries[i].key, key) == 0) {
            return i;
        }
    }
        
    return -1;
}

int jd_dict_delete(jd_dict *dict, char* key) {
    int i = jd_dict_index(dict, key);
    if (i == -1) return -1;
    dict->entries[i] = dict->entries[dict->len - 1];
    dict->len--;

    return 0;
}

void jd_dict_free(jd_dict *dict) {
    if (dict == NULL) return;

    for (int i=0; i < dict->len; i++) {
        free(dict->entries[i].key);
        //free(dict->entries[i].val);
    }
    free(dict->entries);
    free(dict);
}