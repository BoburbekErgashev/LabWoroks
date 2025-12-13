#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

item *item_create(char *key, char *value){
    item  *temp_item = (item*)malloc(sizeof(item));
    temp_item->key = (char*)malloc(strlen(key)+1);
    strcpy(temp_item->key, key);
    temp_item->value = (char*)malloc(strlen(value)+1);
    strcpy(temp_item->value, value);
    return temp_item;
}

void item_print(item *item_ptr){
    printf("\n\nItem key is: %s", item_ptr->key);
    printf("\nItem value is: %s", item_ptr->value);
}

void item_free(item *item_ptr){
    free(item_ptr->key);
    free(item_ptr->value);
    free(item_ptr);
}

void item_update_value(item *item_ptr, char *new_value){
    free(item_ptr->value);
    item_ptr->value = malloc(strlen(new_value) + 1);
    strcpy(item_ptr->value, new_value);
}