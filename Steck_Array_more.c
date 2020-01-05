// StackArray.cpp : Defines the entry point for the console application.
//  Written for Mivhan

#include "stdio.h"

#define MAX_LEN		10

int gl_StackArr[MAX_LEN];
int gl_CurrentIndex = 0;

int Pop();
void PrintStack();

int main()
{
	int Temp;
	printf("StackArray \n");


	Temp = Pop();
	printf("After Pop %d \n", Temp);
	PrintStack();
	return 0;
}

int Pop()
{
	int LastItem;
	if (gl_CurrentIndex <= 0) {				///???
		return 0;  //Stack is Empty
	}
	gl_CurrentIndex--;					///???
	LastItem = gl_StackArr[gl_CurrentIndex];			///???
	return LastItem;
}
void PrintStack()
{
	int i, Temp;
	for (i = 0; i < gl_CurrentIndex; i++) {
		Temp = gl_StackArr[i];
		printf(" %d ", Temp);
	}
	printf("\n");
}
//=========================//