/* CS261- Assignment 1 - Q.4*/
/* Name:Philip Chang
 * Date:January 22, 2017
 * Solution description: intializaties integer n, allocates memory for n students, then generate
 * unique id's and scores, prints the contents of array, then sorts it, and prints it out.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    struct student temp;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (n - 1); j++){
            if(students[j].score > students[j+1].score){
                temp = students[j+1];
                students[j+1] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    /*Allocate memory for n students using malloc.*/
    struct student *stu = (struct student *)malloc(n*sizeof(struct student));
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    int random;
    int check;
    
    for (int i = 0; i < n; i++){
        do{
            random = rand() % n + 1;
            check = 1;
            for (int j = 0; j < i; j++){
                if (stu[j].id == random){
                    check = 0;
                }
            }
        }while (check == 0);
        stu[i].id = random;
        stu[i].score = rand() % 101;
    }
    /*Print the contents of the array of n students.*/
    for (int i = 0; i < n; i++){
        printf("ID: %d  Score: %d \n", stu[i].id, stu[i].score);
    }
    /*Pass this array along with n to the sort() function*/
    sort(stu, n);
    /*Print the contents of the array of n students.*/
    printf("\n Sorted Scores \n");
    for (int i = 0; i < n; i++){
        printf("ID: %d  Score: %d \n", stu[i].id, stu[i].score);
    }
    return 0;
}
