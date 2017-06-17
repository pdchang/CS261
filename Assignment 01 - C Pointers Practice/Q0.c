/* CS261- Assignment 1 - Q. 0*/
/* Name:Philip Chang
 * Date:January 22, 2017
 * Solution description: Prints the address of x, prints value that iptr points to, address
 *						pointed to by iptr, address of iptr itself and the value of x.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	 printf("The value pointed to by iptr: %d \n", *iptr);
     /*Print the address pointed to by iptr*/
	 printf("The address pointed to by iptr: %p \n", iptr);
     /*Print the address of iptr itself*/
	 printf("The address of iptr itself: %p \n", &iptr);
}

int main(){
    
    /*declare an integer x*/
	int x = 33;
    /*print the address of x*/
	printf("The address of x: %p \n", &x);
    /*Call fooA() with the address of x*/
	fooA(&x);
    /*print the value of x*/
	printf("The value of x: %d \n", x);
    return 0;
}
