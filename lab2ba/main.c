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


void read_function(char filename[30]){
    FILE *fptr = fopen(filename, "r");
    file_list *temp = malloc(sizeof(file_list));
    temp->file_pointer = fptr;
    strcpy(temp->filename, filename);
    temp->next = NULL;
    if (opened_files == NULL){
        opened_files = temp;
    }else{
        file_list *current = opened_files;
        while (current->next != NULL){
           current = current->next;
        }
        current->next = temp;
    }
}


int check_files(char filename[30]){
    file_list *temp = opened_files;
    if(opened_files == NULL){
        return 0;
    }else{
        while(temp != NULL){
            if(strcmp(filename, temp->filename) == 0){
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }
}


void read_file(char filename[30]){
    if(check_files(filename) == 0){
        read_function(filename);
    }
}


st_list *find_stl(char filename[30]){
    file_list *temp = opened_files; 
    while(temp !=NULL){
        if(strcmp(filename, temp->filename) == 0){
            return temp->head;
        }
        temp = temp->next;
    }
}


int main(){
    int a;
    char file[30];
    while(1){
        printf("\nEnter action\n");
        scanf("%d", &a);
        if(a == 1){
            printf("\nEnter  filename to check if it is exist\n");
            scanf("%s", file);
            if(check_files(file) == 1){
                printf("File exist\n");
            }else{
                printf("File does not exist\n");
            }
        }else{
            printf("\nEnter  filename to load it into memory\n");
            scanf("%s", file);
            read_file(file);
            printf("\nLoaded\n");
        }
    }
    return 0;
}