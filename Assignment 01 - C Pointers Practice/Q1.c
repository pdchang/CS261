/* CS261- Assignment 1 - Q.1*/
/* Name:Philip Chang
 * Date:January 22, 2017
 * Solution description:Program that allocates memory for ten students and generates ids and scores, then outputs the ids
 * and scores of all students, prints the miniumum and maximum score, and average score of the ten students, then frees
 * the memory allocated by stud. 
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student *stu;
    stu = malloc(10 * sizeof(struct student));
     /*return the pointer*/
	return stu;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    int random;
    int check;
 
    for (int i = 0; i < 10; i++){
        do{
            random = rand() % 10 + 1;
            check = 1;
            for (int j = 0; j < i; j++){
                if (students[j].id == random){
                    check = 0;
                }
            }
        }while (check == 0);
        students[i].id = random;
        students[i].score = rand() % 101;
    }
}
void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	for (int i = 0; i < 10; i++) {
		printf("ID%d Score%d \n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min = students[0].score;
    int max = students[0].score;
    int total = 0;
    double average;
    
    for (int i = 0; i < 10; i++){
        if (students[i].score < min){
            min = students[i].score;
        }
        if (students[i].score > max){
            max = students[i].score;
        }
        total = total + students[i].score;
    }
    average = total / 10;
    printf("minimum: %d \n", min);
    printf("maximum: %d \n", max);
    printf("average: %f \n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
