#include <stdbool.h>
static char look;
void newLine(bool);

char* getName(); // read an identifier
char* getNum(); // read a number

/* what character $look should-must (respectively) be? */
bool match(char c); // return true if $c is $look (cur tok)
void expect(char c); // abort if $c is not as same as $look

/* TO HANDLE WHITESPACES */
bool isWhitespace();
void skipWhitespace(); // skip the current token

/* FOR INFORMATION ON THESE, REFER TO BNF FILE */
int factor();
int term();
int expression();
void assingment(const char*);