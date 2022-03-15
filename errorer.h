#ifndef ERR_RAISER_H
#define ERR_RAISER_H

/* error types */
#define IDENTIFIER_DOESNT_EXIST -1
#define LETTER_EXPECTED -2
#define NUMBER_EXPECTED -3
#define UNEXPECTED_CHAR  -4
#define INVALID_INPUT -5
#define MALFORMED_ASSIGNMENT -6 // assignment didn't start with $

/* print the error and abort the program */
void fatal_error(char *err);

/* for errors related to internal behavior */
void internal_error(char *err);

/* print the error with its type but don't abort */
void error(int type, char *msg);
#endif