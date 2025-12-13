#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "item.h"

typedef struct hashtable{
    item **hash_table;
    int ht_size;
}hashtable;

hashtable *ht_create(int table_size);
char ht_hash(char key[20], int table_size);
char ht_print(char key[20], int table_size);
void ht_insert(hashtable *ht_poiner, item *item_pointer);
void ht_print_value(char *key, hashtable *ht_pointer);

#endif