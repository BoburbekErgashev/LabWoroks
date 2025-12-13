#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

linkedlist *cycle_c(int size, int start){
    linkedlist *head = malloc(sizeof(linkedlist));
    head->num = start;
    linkedlist *temp;
    linkedlist *previous = head;
    for(int i = start + 1; i <= size; i++){
        temp = malloc(sizeof(linkedlist));
        temp->num = i;
        previous->next = temp;
        previous = temp;
    }
    temp->next = head;
    return head;
}