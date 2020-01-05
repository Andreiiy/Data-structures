// QueueArray.cpp : Defines the entry point for the console application.
//Written for Mivhan
//Queue without overriding

#include "stdio.h"

#define  ARR_LEN			4

int gl_HeadIndex = 0;
int gl_BackIndex = 0;
int gl_CurrentSize = 0;
int gl_QueueArray[ARR_LEN];

void AddToQueue(int NewItem);
int GetFromQueue();
void PrintQueue();

int main()
{
	int Temp;
	printf("QueueArray \n");

	AddToQueue(1);
	AddToQueue(3);
	AddToQueue(5);
	AddToQueue(7);
	AddToQueue(9);
	PrintQueue();


	return 0;
}
void AddToQueue(int NewItem)
{
	if (gl_CurrentSize >= ARR_LEN) {
		return;  //Not good
	}
	gl_QueueArray[gl_BackIndex] = NewItem;
	gl_CurrentSize++;

	gl_BackIndex++;					///????

	if (gl_BackIndex == ARR_LEN) {		///????
		gl_BackIndex = 0;
	}
}

void PrintQueue()
{
	int i, TempIndex;
	int Item;

	TempIndex = gl_HeadIndex;
	for (i = 0; i < gl_CurrentSize; i++) {
		Item = gl_QueueArray[TempIndex];
		printf(" %d ", Item);
		TempIndex++;
		if (TempIndex == ARR_LEN) {		///????
			TempIndex = 0 ;	///????
		}
		printf("\n");
	}
}