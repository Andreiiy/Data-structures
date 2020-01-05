#include<stdio.h>


#define Big 5


int iArray[Big];
int iIndex=0;

void Push(int num) 
{
	if (iIndex >= Big)
		printf("Steck is full");
	iArray[iIndex++] = num;

}

int Pop()
{
	int rezalt;
	if (iIndex <= 0)
		printf("Steck is empty");
	rezalt=iArray[iIndex--];
	return	rezalt;


}

void PrintSteck()
{
	int i;
	for ( i = 0; i < iIndex; i++)
	{
		printf("%d ", iArray[i]);
	}
}

void main() 
{
	Push(6);
	Push(66);
	Push(7);
	Push(77);
	Push(8);

	Pop();
	Pop();


	PrintSteck();
}
