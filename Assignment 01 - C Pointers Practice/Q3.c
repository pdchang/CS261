/* CS261- Assignment 1 - Q.3*/
/* Name:Philip Chang
 * Date:January 22, 2017
 * Solution description: creates an array, filled with random numbers, prints the contents,
 * then sorts it and prints the contents again
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (n - 1); j++){
            if(number[j] > number[j+1]){
                int temp = number[j+1];
                number[j+1] = number[j];
                number[j] = temp;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *array = (int *)malloc(n*(sizeof(int)));
    /*Fill this array with random numbers, using rand().*/
    for (int i = 0; i < n; i++){
        array[i] = rand() % RAND_MAX;
    }
    /*Print the contents of the array.*/
    for (int i = 0; i < n; i++){
        printf("Array[%d] = %d \n", i, array[i]);
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    /*Print the contents of the array.*/    
    printf("\n Sorted Array \n");
    for (int i = 0; i < n; i++){
        printf("Array[%d] = %d \n", i, array[i]);
    }
    return 0;
}
