// PList.cpp : Defines the entry point for the console application.
//

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

int DeleteItemByVal(int Xi_iVal);
void PrintList(char *Xi_psText);

//===================================//
int main()
{
	printf("Hello PList \n");

	PrintList("From Start \n");


	DeleteItemByVal(0);
	DeleteItemByVal(4);
	DeleteItemByVal(8);


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
void PrintList(char *Xi_psText)
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
int DeleteItemByVal(int Xi_iVal)
{	//list sorted from small to big numbers 

	struct ST_ITEM *l_pstItemToDelete;
	struct ST_ITEM *l_pStCurrentItem;

	if (gl_pstHeadItem == 0) {						///???
		PrintList("DeleteItemByVal error");
		return 0;
	}

	if (gl_pstHeadItem->m_iVal == Xi_iVal) {			///???
		l_pstItemToDelete = gl_pstHeadItem;			///???
		gl_pstHeadItem = gl_pstHeadItem->m_pNext;
		free(l_pstItemToDelete);
		PrintList("After DeleteItemByVal");
		return 1;
	}

	l_pStCurrentItem = gl_pstHeadItem;					///???
	while ((l_pStCurrentItem->m_pNext != 0)
		&& (Xi_iVal != l_pStCurrentItem->m_pNext->m_iVal)) {	///???
		l_pStCurrentItem = l_pStCurrentItem->m_pNext;			///???
	}

	l_pstItemToDelete = l_pStCurrentItem->m_pNext;
	l_pStCurrentItem->m_pNext = l_pstItemToDelete->m_pNext;
	free((void * )l_pstItemToDelete);				///???

	PrintList("After DeleteItemByVal");
	return 1;
}
//=======================================//