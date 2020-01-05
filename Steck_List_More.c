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

int PopHead();
//===================================//
int main()
{
	int iVal;

	printf("Stack List \n");

	iVal = PopHead();
	printf("Pop Value = %d \n", iVal);

	return 0;
}




//=======================================//
int PopHead()
{
	int iVal;
	struct ST_ITEM *l_pstPopItem = 0;


	if (gl_pstHeadItem == 0) {
		printf("Stack is empty \n");
		return 0;  //Not good
	}

	l_pstPopItem = gl_pstHeadItem;			///???
	gl_pstHeadItem = l_pstPopItem->m_pNext;		///???

	if (l_pstPopItem) {
		iVal = l_pstPopItem->m_iVal;	///???
		free((void*)l_pstPopItem);	///???
	}

	return iVal;
}
//=======================================//