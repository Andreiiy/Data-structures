//StackList.c : Defines the entry point for the console application.
//Written for Mivhan

#include "stdio.h"
#include "stdlib.h"


//===================================//
// Structure declarations
//===================================//
struct ST_ITEM
{
	int m_iVal;
	struct ST_ITEM *m_pNext;
};

struct ST_ITEM *gl_pstHeadItem = 0;

//===================================//
// Function declarations
//===================================//
struct ST_ITEM *CreateItem(int Xi_iVal);
int GetFromHead();
void PrintQueue(char *Xi_psText);

//===================================//
int main()
{
	int iVal;

	printf("Queue List \n");

	PrintQueue("From Start \n");


	iVal = GetFromHead();
	printf("GetFromHead Value = %d \n", iVal);
	iVal = GetFromHead();
	printf("GetFromHead Value = %d \n", iVal);

	return 0;
}
//===================================//
struct ST_ITEM *CreateItem(int Xi_iVal)
{
	struct ST_ITEM *l_pStCurrentItem = (struct ST_ITEM *)malloc(sizeof(struct ST_ITEM));
	if (!l_pStCurrentItem)
	{
		printf("CreateItem Malloc Error \n");
		return 0;
	}
	l_pStCurrentItem->m_iVal = Xi_iVal;
	l_pStCurrentItem->m_pNext = 0;

	return l_pStCurrentItem;
}
//=======================================//
void PrintQueue(char *Xi_psText)
{
	int i = 0;
	struct ST_ITEM *l_pStCurrentItem;

	if (gl_pstHeadItem == 0) {
		printf("List is empty \n");
		return;
	}

	printf("\n%s : \n", Xi_psText);

	l_pStCurrentItem = gl_pstHeadItem;
	while (l_pStCurrentItem) {
		printf("Index = %d, m_iVal = %d, m_pNext = %p \n",
			i, l_pStCurrentItem->m_iVal, l_pStCurrentItem->m_pNext);
		l_pStCurrentItem = l_pStCurrentItem->m_pNext;
		i++;
	}
}

//=======================================//
int GetFromHead()
{
	int iVal;
	struct ST_ITEM *l_pstPopItem = 0;


	if (gl_pstHeadItem == NULL ) {		///???
		printf("Stack is empty \n");
		return 0;  //Not good
	}

	l_pstPopItem = gl_pstHeadItem;           // ????????????
		gl_pstHeadItem = gl_pstHeadItem->m_pNext;	///???

	if (l_pstPopItem) {
		iVal = l_pstPopItem->m_iVal;	///???
		free((void *)l_pstPopItem);
	}
	PrintQueue("After GetFromHead");
	return iVal;
}
//=======================================//