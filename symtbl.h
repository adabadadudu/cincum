#ifndef SYMTBL_H
#define SYMTBL_H
/* Symbol table implemented by linked lists */
#include <stdbool.h>

#define MAX_STR_LEN 45 /* length of an identifier */

/* sym tbl linklist. assigned a value to each name */
struct Var
{
    char name[MAX_STR_LEN];
    int value;
    struct Var *next;
};

/*
* returns a pointer to the element
* that is the same as passed arg
* to lookup(), NULL if not found
*/
struct Var* lookup(struct Var*,const char[]);

/* return a node with the given attributes */
struct Var* Node(const char[], int);

/* 
* creates a node with the given attrs
* and inserts it at the start if does
* not exist. raises an error if exist
*/
void push(struct Var**, const char[], int);

/* modifies value of the var with given name*/
void set(struct Var*, const char[], int);

/* 
* it passed given args to the function push if
* the var doesn't exist, func set() otherwise
* always use it in the case of push() or set()
*/
void assign(struct Var**, const char[], int);

/* get value of element with the passed name */
int get(struct Var*, const char[]);
#endif