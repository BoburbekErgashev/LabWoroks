#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "item.h"

int hash_function(int table_size, char key[20]){
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * 31) + key[i];
    }
    return hash % table_size;
}

hashtable *ht_create(int table_size){
    hashtable *ht = malloc(sizeof(hashtable));
    ht->ht_size = table_size;
    ht->hash_table = malloc(sizeof(item*) * table_size);
    for (int i = 0; i < table_size; i++){
        ht->hash_table[i] = NULL;
    }
    return ht;
}

char ht_print(char key[20], int table_size){
    printf("\n\n Hash index for key '%s' and table size %d is %d\n", key, table_size, hash_function(table_size, key));
}

void ht_insert(hashtable *ht_pointer, item *item_pointer){
    ht_pointer->hash_table[hash_function(ht_pointer->ht_size,item_pointer->key)] = item_pointer;
}

void ht_print_value(char *key, hashtable *ht_pointer){
    item *value = ht_pointer->hash_table[hash_function(ht_pointer->ht_size, key)];
    if(value == NULL){
        printf("Value not found");
    }else{
        if(strcmp(value->key, key) == 0){
            printf("Stored value of key:'%s' '%s'", key, value->value);
        }
    }
}