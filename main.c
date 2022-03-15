#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "main.h"
#include "symtbl.h"
#include "errorer.h"

static char get_name[9], get_number[9];

static struct Var *TABLE; // symbol table

void getChar(){scanf("%c",&look);}

char* getName(){
	if(!isalpha(look))
		error(LETTER_EXPECTED ,"An identifier must start with a letter");
	char *name = get_name;
	for(int i=0; i < 8 && isalnum(look); i++, getChar())
		*name++ = look;
	*name = '\0';
	skipWhitespace();
	return get_name; // $*name points to get_name
}

char* getNum(){
	if(!isdigit(look))
		error(NUMBER_EXPECTED ,"A number must start with a digit");
	char *num = get_number;
	for(int i=0; i < 8 && isdigit(look); i++, getChar())
		*num++ = look;
	*num = '\0';
	skipWhitespace();
	return get_number; // $*num points to get_name
}

bool match(char c){
	if(c != look)
		return false;
	getChar();
	skipWhitespace();
	return true;
}

void expect(char c){
	if(!match(c)){
		char str[12];
		sprintf(str, "%c unexpected", look);
		error(UNEXPECTED_CHAR, str);
	}
}

bool isWhitespace(){
	if(look == ' ' || look == '\t')
		return true;
	return false;
}

void skipWhitespace(){
	if(isWhitespace())
		getChar();
}

int factor(){
	if(look == '('){
		expect('(');
		int val = expression();
		expect(')');
		return val;
	} else if(isdigit(look))
		return atoi(getNum());
	else if (isalpha(look))
		return get(TABLE, getName());
	else {
		error(INVALID_INPUT, "Your input isn't valid");
		getChar();
		newLine(false);
	}
}

int term(){
	int value = factor();
	while(look == '*' || look == '/'){
		switch(look){
			case '*':
				expect('*');
				value = value * factor();
				break;
			case '/':
				expect('/');
				value = value / factor();
				break;
		}
	}
	return value;
}

int expression(){
	int value;
	if(look == '+' || look == '-')
		value = 0;
	else 
		value = term();
	while(look == '+' || look == '-'){
		switch(look){
			case '+':
				expect('+');
				value = value + term();
				break;
			case '-':
				expect('-');
				value = value - term();
				break;
		}
	}
	return value;
}

void assignment(){
	if(look == '$'){
		getChar(); /* do not use match() because it skip whitespaces
		so an instruction like `$    hello` is still correct */
		char *name = getName();
		expect('=');
		assign(&TABLE, name, expression());
	} else 
		error(MALFORMED_ASSIGNMENT, "An assignment must start with a $");
}

// MICRO FUNCTIONS
void init(){ getChar(); }
void newLine(bool must){
	if(must){
		skipWhitespace();
		if(match('\n')){
			/* match skipped newline */
		} else {
			printf("newline expected\n");
			while(look != '\n')
				getChar(); // skip until newline
			getChar(); // skip newline
		}
	} else
		while(look == '\n' || isWhitespace())  getChar();
}

void block(){
	while(look != '@') {
		if(look == '$')
			assignment();
		else 
			printf("=:> %d\n",expression());
		
		if(look != '@')
			newLine(true);
	}
}

int main(){
	init();
	block();
	return 0;
}
