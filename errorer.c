#include <stdio.h>
#include <stdlib.h>

#include "errorer.h"
#include "main.h"

/* return a string contains error type */
static char* getErrorType(int);

void fatal_error(char *err){
    printf("%s", err);
    exit(1);
}

void internal_error(char *err){
    #define EMAIL "pooia.ferdowsi.is.developer@gmail.com"
    printf(
        "Unfortunately an internal error occured\n" \
        "In this case, it is'nt your mistake but mine\n" \
        "Please mail me at \"%s\"\n" \
        "then paste the error as message & send\n" \
        "I'll answer as fast as I can. \n" \
        "ERROR: %s\n", EMAIL, err);
        exit(1);
}

void error(int type, char *msg){
    char *err_type = getErrorType(type);
    printf("%s: %s\n", err_type, msg);
    exit(1);
}

static char* getErrorType(int type){
    switch(type){
        case IDENTIFIER_DOESNT_EXIST:
            return "identifier doesn't exist";
            break;
        case LETTER_EXPECTED:
            return "letter expected";
            break;
        case NUMBER_EXPECTED:
            return "number expected";
            break;
        case UNEXPECTED_CHAR:
            return "unexpected char";
            break;
        case INVALID_INPUT:
            return "invalid input";
            break;
        case MALFORMED_ASSIGNMENT:
            return "malformed assignment";
            break;
        default:
            internal_error("The error type doesn't exist");
    }
}