#include <stdio.h>

#define MAX_LEN 4

int iHead = 0;
int iTail = 0;
int iCounter = 0;

int iArr[MAX_LEN];

int PutQ(int iValue)
{
	if (iCounter>= MAX_LEN)
	{
		printf("Queue is full\n");
	}
	iArr[iTail++] = iValue;
	iCounter++;
	if (iTail>= MAX_LEN)
	{
		iTail = 0;
	}

	return 1;
}

int GetQ()
{
	int iVal;
		
	if (iCounter <=0)
	{
		printf("Queue is empty\n");
	}
	iVal = iArr[iHead++];
	iCounter--;
	if (iHead >= MAX_LEN)
	{
		iHead = 0;
	}
	return iVal;
}

void PrintQ()
{

}

void main()
{

}