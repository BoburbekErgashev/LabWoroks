#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

int main(){

    int N, L, S, alive;


    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter Lifes: ");
    scanf("%d", &L);
    printf("Enter steps: ");
    scanf("%d", &S);

    linkedlist *loop = cycle_c(N, 1);
    linkedlist *temp = loop;

    for (int i = 0; i < N; i++){
        temp->life = L;
        temp = temp->next;
    }

    temp = loop;

    linkedlist *temp_next;

    alive = N;

    while(alive > 1){
        for(int j = 3; j <= S; j++){
                temp = temp->next;
            }
        temp->next->life--;
        if(temp->next->life <= 0){
            temp_next = temp->next;
            temp->next = temp->next->next;
            free(temp_next);
            alive--;
        }
        temp = temp->next;
        }
    
    printf("%d", temp->num);
    return 0;
}