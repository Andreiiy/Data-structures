// Tree1.cpp : Defines the entry point for the console application.
// LK. for ORT Hermelin
// 2017.11.27 Version 1.

#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h>	//stdlib.h or malloc.h


#define		LEFT	0
#define		RIGHT	1
//===================================//
// Structure declarations
//===================================//
typedef struct ST_ITEM
{
	int m_iVal;
	struct ST_ITEM *m_pLeft;
	struct ST_ITEM *m_pRight;
} ST_ITEM;

ST_ITEM *gl_pHead;

//===================================//
// Function declarations
//===================================//
ST_ITEM * CreateItem(int Xi_iVal);
ST_ITEM * AddItemToTree(int Xi_iVal, ST_ITEM *Xi_pParent, int Xi_iSide);
int PrintTreeRecursive(ST_ITEM *Xi_pCurrentItem);
void PrintItem(ST_ITEM *Xi_pCurrentItem);
//==================================//
int main()
{
	//gl_	prefix of global variables
	//Xi_	prefix of parameters
	//l_	prefix of local variables
	//s_	prefix of static variables

	//First level
	ST_ITEM *l_pItem1, *l_pItem2;

	//Second level
	ST_ITEM *l_pItem11, *l_pItem12, *l_pItem21, *l_pItem22;

	//Third level
	ST_ITEM *l_pItem111, *l_pItem112, *l_pItem121, *l_pItem122;
	ST_ITEM *l_pItem211, *l_pItem212, *l_pItem221, *l_pItem222;

	gl_pHead = CreateItem(0);

	//Add items to tree
	l_pItem1 = AddItemToTree(1, gl_pHead, LEFT);
	l_pItem2 = AddItemToTree(2, gl_pHead, RIGHT);

	l_pItem11 = AddItemToTree(11, l_pItem1, LEFT);
	l_pItem12 = AddItemToTree(12, l_pItem1, RIGHT);
	l_pItem21 = AddItemToTree(21, l_pItem2, LEFT);
	l_pItem22 = AddItemToTree(22, l_pItem2, RIGHT);

	l_pItem111 = AddItemToTree(111, l_pItem11, LEFT);
	l_pItem112 = AddItemToTree(112, l_pItem11, RIGHT);
	l_pItem121 = AddItemToTree(121, l_pItem12, LEFT);
	l_pItem122 = AddItemToTree(122, l_pItem12, RIGHT);
	l_pItem211 = AddItemToTree(211, l_pItem21, LEFT);
	l_pItem212 = AddItemToTree(212, l_pItem21, RIGHT);
	l_pItem221 = AddItemToTree(221, l_pItem22, LEFT);
	l_pItem222 = AddItemToTree(222, l_pItem22, RIGHT);


	printf("Print the tree:\n");
	PrintTreeRecursive(gl_pHead);
	printf("\n");

	return 0;
}
//==================================//
ST_ITEM *CreateItem(int Xi_iVal)
{
	ST_ITEM *l_pNewItem = (ST_ITEM *)malloc(sizeof(ST_ITEM));
	if (!l_pNewItem)
		return NULL;
	l_pNewItem->m_iVal = Xi_iVal;
	l_pNewItem->m_pLeft = NULL;
	l_pNewItem->m_pRight = NULL;

	return l_pNewItem;
}
//==================================//
ST_ITEM * AddItemToTree(int Xi_iVal, ST_ITEM *Xi_pParent, int Xi_iSide)
{
	if (!Xi_pParent)
		return NULL;

	ST_ITEM *l_pNewItem = CreateItem(Xi_iVal);
	if (!l_pNewItem)
		return NULL;

	//Add new child to parent
	if (Xi_iSide == LEFT)
		Xi_pParent->m_pLeft = l_pNewItem;
	else
		Xi_pParent->m_pRight = l_pNewItem;

	return l_pNewItem;
}
//==================================//
void PrintItem(ST_ITEM *Xi_pCurrentItem)
{
	if (!Xi_pCurrentItem) {
		printf("Error: Zero current item! \n");
		return;
	}
	printf("%d ", Xi_pCurrentItem->m_iVal);
}
	//==================================//
int PrintTreeRecursive(ST_ITEM *Xi_pCurrentItem)
{
	if (!Xi_pCurrentItem) {
		printf("Error: Zero current item! \n");
		return 0;
	}
	if (Xi_pCurrentItem->m_pLeft)
		PrintTreeRecursive(Xi_pCurrentItem->m_pLeft);
	if (Xi_pCurrentItem->m_pRight)
		PrintTreeRecursive(Xi_pCurrentItem->m_pRight);

	PrintItem(Xi_pCurrentItem);

	return 1;
}







