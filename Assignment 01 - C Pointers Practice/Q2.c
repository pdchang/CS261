/* CS261- Assignment 1 - Q.2*/
/* Name:Philp Chang
 * Date:January 22, 2017
 * Solution description:declares integers initalized to values, prints values, calls foo which
 * doubles one integer, halves another, and sets last integer to the sum, prints value of foo
 * the prints the values of integers again, the first and second being changed, and the third
 * remaining the same.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    /*Set b to half its original value*/
    *b = *b / 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    /*Print the values of x, y and z*/
    printf("the value of x is %d \n", x);
    printf("the value of y is %d \n", y);
    printf("the value of z is %d \n", z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int value = foo(&x,&y,z);
    /*Print the value returned by foo*/
    printf("The value returned by foo is %d \n", value);
    /*Print the values of x, y and z again*/
    printf("the value of x is %d \n", x);
    printf("the value of y is %d \n", y);
    printf("the value of z is %d \n", z);
    /*Is the return value different than the value of z?  Why?*/
    //Yes, the return value is different than the value of z because z is passed by value,
    //while x and y and passed by reference, so z is only altered inside the function
    //itself, and z remains untouched in main.
    return 0;
}
    
    
