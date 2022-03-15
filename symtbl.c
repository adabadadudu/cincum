#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "symtbl.h"
#include "main.h"
#include "errorer.h"

struct Var* Node(const char name[], int value){
    struct Var *ptr = malloc(sizeof(struct Var*));
    if(ptr == NULL)
        fatal_error("Can't inittalize a struct. Probably memory lack");
    else {
        strcpy(ptr->name, name);
        ptr->value = value;
        ptr->next = NULL;
        return ptr;
    }
}

struct Var *lookup(struct Var* ptr, const char name[]){
    struct Var *temp = ptr; /* pure ptr */
    while(ptr != NULL){
        if(!strcmp(ptr->name, name))
            return ptr;
        /* else */
        ptr = ptr->next;
    }
    /* if not found */
    return NULL;
}

/* Never invoke it directly. use assign instead */
void push(struct Var **ptr, const char name[], int value){
    struct Var *temp = *ptr;
    (*ptr) = Node(name, value);
    (*ptr)->next = temp;
}

/* Never invoke it directly. use assign instead */
void set(struct Var *ptr, const char name[], int value){
    ptr->value = value;
}

void assign(struct Var **head, const char name[], int value){
    struct Var *temp = lookup(*head, name);
    if(temp == NULL)
        push(head, name, value); // further confirm
    else
        set(temp, name, value);
}

int get(struct Var* head, const char name[]){
    struct Var *ptr = lookup(head, name);
    if(ptr == NULL)
        error(IDENTIFIER_DOESNT_EXIST ,"The given name doesn't exist");
    else return ptr->value;
}
