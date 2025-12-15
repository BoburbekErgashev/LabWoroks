#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct st_list{
    char name[30];
    int mark;
    struct st_list *next;
}st_list;

st_list *student_l = NULL;

void read_file(char filename[30]){
    FILE *fptr = fopen(filename, "r");
    char stname[30] = {};
    int mark;
    st_list *temp;
    while(fscanf(fptr, "%s %d", stname, &mark) != EOF){
        temp = malloc(sizeof(st_list));
        strcpy(temp->name, stname);
        temp->mark = mark;
        if(student_l == NULL){
            temp->next = NULL;
            student_l = temp;
        }else{
            temp->next = student_l;
            student_l = temp;
        }
    }
}

void name_sort(){
    st_list *current, *previous, *temp;
    int swapped = 0;
    do{
        swapped = 0;
        current = student_l;
        previous = NULL;
        while(current != NULL && current->next != NULL){
            if(strcmp(current->name, current->next->name) > 0){
                if(previous == NULL){
                    temp = current->next->next;
                    current->next->next = current;
                    previous = current->next;
                    student_l = current->next;
                    current->next = temp;
                    swapped = 1;
                }else{
                    temp = current->next->next;
                    current->next->next = current;
                    previous->next = current->next;
                    previous = current->next;
                    current->next = temp;
                    swapped = 1;
                }
            }else{
                previous = current;
                current = current->next;
            }
        }

    }while(swapped == 1);
}

int main(){
    char filename[30] = "student.txt";
    read_file(filename);
    name_sort();
    st_list *temp = student_l;
    while(temp != NULL){
        printf("%s %d\n", temp->name, temp->mark);
        temp = temp->next;
    }
}