#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct st_list{
    char name[30];
    int mark;
    struct st_list *next;
}st_list;


typedef struct file_list{
    FILE *file_pointer;
    char filename[30];
    st_list *head;
    struct file_list *next;
}file_list;

file_list *opened_files = NULL;

void read_file(char filename[30], file_list **opened_files){
    FILE *fptr = fopen(filename, "r");
    file_list *temp = malloc(sizeof(file_list));
    temp->file_pointer = fptr;
    strcpy(temp->filename, filename);
    temp->next = NULL;
    if (opened_files == NULL){
        *opened_files = temp;
    }else{
        file_list *current = opened_files;
        while (current->next != NULL){
           current = current->next;
        }
        current->next = temp;
        
    }
}