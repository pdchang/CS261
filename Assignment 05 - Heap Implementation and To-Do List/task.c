/*******************************************************************
** Program Filename: Assignment 5 - task.c
** Author: Philip Chang
** Date: March 5, 2017
** Description: Task Implementation
*******************************************************************/

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
    // FIXME: implement
	struct Task *new = (struct Task*)malloc(sizeof(Task));
	strcpy(new->name, name);
	new->priority = priority;
	return new;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return 
 */
int taskCompare(void* left, void* right)
{
	// FIXME: implement
	struct Task *lefty = (struct Task *)left;
	struct Task *righty = (struct Task *)right;

	if (lefty->priority < righty->priority) {
		return -1;
	}
	else if (lefty->priority > righty->priority) {
		return 1;
	}
	else {
		return 0;
	}
}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}
