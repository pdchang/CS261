/*******************************************************************
** Program Filename: Assignment 5 - toDo.c
** Author: Philip Chang
** Date: March 5, 2017
** Description: To-Do List implementation
*******************************************************************/

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{
    // FIXME: Implement
	int priority;
	char *fname = (char *)malloc(sizeof(char) * 42);
	char *info = (char *)malloc(sizeof(char) * 420);
	switch (command) {
	case 'l':

		printf("Please enter the filename: ");
		fgets(fname, 420, stdin);
		if (fname[strlen(fname) - 1] == '\n') {
			fname[strlen(fname) - 1] = 0;
		}
		FILE *looky = fopen(fname, "r");
		listLoad(list, looky);
		printf("The list has been loaded from file successfully. \n\n");
		fclose(looky);
		break;
	case 's':
		printf("Please enter the filename: ");
		fgets(fname, 420, stdin);
		if (fname[strlen(fname) - 1] == '\n') {
			fname[strlen(fname) - 1] = 0;
		}
		FILE *namer = fopen(fname, "w");
		listSave(list, namer);
		printf("List has been saved into the file successfully. \n\n");
		fclose(namer);
		break;
	case 'a':
		printf("Please enter the task description: ");
		fgets(info, 420, stdin);
		if (info[strlen(info) - 1] == '\n') {
			info[strlen(info) - 1] = 0;
		}
		printf("Please enter the task priority (0-999): ");
		scanf("%d", &priority);
		while (getchar() != '\n');
		Task *newTask = taskNew(priority, info);
		dyHeapAdd(list, newTask, taskCompare);
		printf("The task '%s' has been added to your to-do list.\n\n", info);
		break;
	case 'g':
		if (dySize(list) == 0) {
			printf("Your to-do list is empty! \n \n");
		}
		else {
			struct Task *first = (struct Task*)dyHeapGetMin(list);
			printf("Your first task is: %s \n", first->name);
		}
		break;
	case 'r':
		if (dySize(list) == 0) {
			printf("Your to-do list is empty! \n \n");
		}
		else {
			struct Task *byebye;
			byebye = (struct Task *)dyHeapGetMin(list);
			printf("Your first task '%s' has been removed from the list. \n \n", byebye->name);
			dyHeapRemoveMin(list, taskCompare);
			taskDelete(byebye);
		}
		break;
	case 'p':
		if (dySize(list) == 0) {
			printf("Your to-do list is empty! \n \n");
		}
		else {
			listPrint(list);
		}
		break;
	case 'e':
		printf("\n Bye! \n");
		break;
	}

}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */
	for (int i = 0; i < dySize(list); i++) {
		Task *eraser = dyGet(list, i);
		taskDelete(eraser);
	}

    dyDelete(list);
    return 0;
}