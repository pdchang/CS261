/********************************************************************
 ** Program Filename: Assignment 2 - stackapp.c
 ** Author: Philip Chang
 ** Date: January 29, 2017
 ** Description: Stack Application
 *******************************************************************/
/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
    if (s == 0){
        return 1;
    }
    char c;
    DynArr *check1 = newDynArr(1);
    c = nextChar(s);
    char t = '\0';
    do{
        if(c == '{' || c == '[' || c == '('){
            pushDynArr(check1, c);
        }
        if(!isEmptyDynArr(check1)){
            t = topDynArr(check1);
        }
        if(c == '}' && t == '{'){
            if(isEmptyDynArr(check1)){
                return 0;
            }
            popDynArr(check1);
        }
        if(c == ']' && t == '['){
            if(isEmptyDynArr(check1)){
                return 0;
            }
            popDynArr(check1);
        }
        if(c == ')' && t == '('){
            if(isEmptyDynArr(check1)){
                return 0;
            }
            popDynArr(check1);
        }
        c = nextChar(s);
    }while(c != '\0');
    
    if(isEmptyDynArr(check1)){
        deleteDynArr(check1);
        return 1;
    }
    else{
        deleteDynArr(check1);
        return 0;
    }
    
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

