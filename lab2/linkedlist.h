#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct linkedlist {
    int num;
    int life;
    struct linkedlist *next;
} linkedlist;

linkedlist* cycle_c(int size, int start);

#endif