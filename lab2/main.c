#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

int main(){

    int N, L;


    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter Lifes: ");
    scanf("%d", &L);

    linkedlist *loop = cycle_c(N, 1);
    linkedlist *temp = loop;

    for (int i = 0; i < N; i++){
        temp->life = L;
        temp = temp->next;
    }

    linkedlist *temp = loop;
    linkedlist *teemp_next = malloc(sizeof(linkedlist));

    for (int i = N; i > 1; i--){
        for(int j = 1; j <=4; j++){
            if (j == 4)
            {
                if (temp->life <= 0){
                    
                    temp->next = temp->next->next;
                }
            }
            temp = temp->next;
        }
    }
    
    printf("%d", temp->num);
    return 0;
}