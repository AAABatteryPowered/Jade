#include "../../../include.h"

// Static Helpers
static int jd_dict_index(jd_dict *dict, char *key) {
    for (int i = 0; i < dict->len; i++) {
        if (strcmp(dict->entries[i].key, key) == 0) {
            return i;
        }
    }
        
    return -1;
}

static inline int next_power_of_2(int x)
{
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x + 1;
}

// Helpers

void jd_dict_print(jd_dict *dict, int max) {
    printf("[jade] Length: %d\n[jade] Cap: %d\n", dict->len, dict->cap);

    if (max > dict->len) {
        max = dict->len;
    }

    for (int i = 0; i < max; i++) {
        jd_value value = dict->entries[i].val;
        printf("[jade] [%d] %s -> ", i, dict->entries[i].key);
        switch (value.type) {
        case JD_INT:
            printf("%d", value.v_int);
            break;

        case JD_STRING:
            printf("\"%s\"", value.v_string);
            break;

        case JD_BOOL:
            printf(value.v_bool ? "true" : "false");
            break;

        case JD_NULL:
            printf("null");
            break;

        default:
            printf("<unknown>");
            break;
        }
        printf("\n");
    }

    int remaining = dict->len - max;
    if (remaining > 0) {
        printf("%d Entries Remain Unprinted\n", remaining);
    }
}

// Constructors
#define jd_dict() &(jd_dict){malloc(8 * sizeof(jd_dict_entry)), 0, 8}

jd_dict jd_dict_new(int size) {
    jd_dict dict;

    dict.cap = next_power_of_2(size);
    dict.entries = malloc(dict.cap * sizeof(jd_dict_entry));
    dict.len = 0;
    
    return dict;
}

jd_value* jd_dict_get(jd_dict *dict, char* key) {
    for (int i=0; i < dict->len; i++) {
        if (strcmp(dict->entries[i].key, key) == 0) {
            return &dict->entries[i].val;
        }
    }

    return NULL;
}

int jd_dict_set(jd_dict *dict, jd_dict_entry *entry) {
    int index = jd_dict_index(dict, entry->key);
    if (index == -1) {
        if ((dict->len) == dict->cap) {
            dict->cap *= 2;
            jd_dict_entry *tmp = realloc(dict->entries, dict->cap * sizeof(jd_dict_entry));
            if (tmp == NULL) return -1;
            dict->entries = tmp;
        }
        dict->entries[dict->len] = *entry;
        dict->len++;
    } else {
        dict->entries[index] = *entry;
    }
    
    return 0;
}

int jd_dict_delete(jd_dict *dict, char* key) {
    int i = jd_dict_index(dict, key);
    if (i == -1) return -1;

    free(dict->entries[i].key);
    if (dict->entries[i].val.type == JD_STRING) {
        free(dict->entries[i].val.v_string);
    }

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