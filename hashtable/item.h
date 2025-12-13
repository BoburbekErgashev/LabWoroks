#ifndef ITEM_H
#define ITEM_H

typedef struct item{
    char *key;
    char *value;
}item;

item *item_create(char *key, char *value);
void item_print(item *item_ptr);
void item_free(item *item_ptr);
void item_update_value(item *item_ptr, char *new_value);

#endif