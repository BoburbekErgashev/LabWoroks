#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "hashtable.h"



int main(){
    char key[20] = "fruit";
    char value[20] = "apple";

    item *narsa = item_create(key, value);
    hashtable *ht_first = ht_create(10);

    ht_insert(ht_first, narsa);
    scanf("%s", key);
    printf("\n");
    ht_print_value(key, ht_first);
    
    return 0;
}