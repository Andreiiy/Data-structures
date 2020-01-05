// Tree5.cpp : Defines the entry point for the console application.
// LK. for ORT Hermelin
// 2017.12.31 Version 5.

#define _CRT_SECURE_NO_WARNINGS

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
	int m_Id;
	int m_iVal;
	char m_sName[12];
	struct ST_ITEM *m_pLeft;
	struct ST_ITEM *m_pRight;
} ST_ITEM;

ST_ITEM *gl_pHead;

int gl_ItemsPerLevelArr[100] = { 8, 8, 8, 8 };
int gl_ItemsOnLevel = 0;
int gl_MaxLevels = 0;

//===================================//
// Function declarations
//===================================//
ST_ITEM * CreateItem(int Xi_iVal);
void PrintItem(ST_ITEM *Xi_pCurrentItem);


ST_ITEM * AddItemToTree(int Xi_iVal, ST_ITEM *Xi_pParent, int Xi_iSide);
int CountTreeLevelsRecursive(ST_ITEM *Xi_pCurrentItem);
int FindItemByIdRecursive(ST_ITEM *Xi_pCurrentItem, ST_ITEM **Xi_ppResultItem, int Xi_Id);


//==================================//
int main()
{
	//gl_	prefix of global variables
	//Xi_	prefix of parameters
	//l_	prefix of local variables
	//s_	prefix of static variables

	//Work with tree

	return 0;
}
//==================================//
ST_ITEM *CreateItem(int Xi_Id)
{
	ST_ITEM *l_pNewItem = (ST_ITEM *)malloc(sizeof(ST_ITEM));
	if (!l_pNewItem)
		return NULL;

	l_pNewItem->m_Id = Xi_Id;
	l_pNewItem->m_iVal = 1;
	sprintf(l_pNewItem->m_sName, "Name_%d", Xi_Id);

	l_pNewItem->m_pLeft = NULL;
	l_pNewItem->m_pRight = NULL;

	return l_pNewItem;
}
//==================================//
void PrintItem(ST_ITEM *Xi_pCurrentItem)
{
	if (!Xi_pCurrentItem) {
		printf("Error: Zero current item! \n");
		return;
	}
	printf("%d ", Xi_pCurrentItem->m_Id);
}

//==================================//
ST_ITEM * AddItemToTree(int Xi_iVal, ST_ITEM *Xi_pParent, int Xi_iSide)
{
	ST_ITEM *l_pNewItem;

	if (!Xi_pParent)
		return NULL;

	l_pNewItem = CreateItem(Xi_iVal);
	if (!l_pNewItem)
		return NULL;

	//Add new child to parent
	if (Xi_iSide == LEFT)
		Xi_pParent->m_pLeft = l_pNewItem;	///???
	else
		Xi_pParent->m_pRight = l_pNewItem;

	return l_pNewItem;
}

//==================================//
int CountTreeLevelsRecursive(ST_ITEM *Xi_pCurrentItem)
{
	static int s_CurrentLevel = -1;
	static int s_MaxLevel = -1;

	s_CurrentLevel++;
	if (s_CurrentLevel > s_MaxLevel) {
		s_MaxLevel = s_CurrentLevel;
	}
	if (!Xi_pCurrentItem) {
		printf("Error: Zero current item! \n");
		s_CurrentLevel--;
		return s_MaxLevel + 1;
	}

	if (Xi_pCurrentItem->m_pLeft)			///???
		CountTreeLevelsRecursive(Xi_pCurrentItem->m_pLeft);	///???
	if (Xi_pCurrentItem->m_pRight)
		CountTreeLevelsRecursive(Xi_pCurrentItem->m_pRight);

	s_CurrentLevel--;					///???
	return s_MaxLevel + 1;		///???
}


//==================================//
int FindItemByIdRecursive(ST_ITEM *Xi_pCurrentItem, ST_ITEM **Xi_ppResultItem, int Xi_Id)
{

	if (!Xi_pCurrentItem) {
		printf("Error: Item with ID = %d not found! \n", Xi_Id);
		return 0;
	}
	if (Xi_Id == Xi_pCurrentItem->m_Id) {		///???
		*Xi_ppResultItem = Xi_pCurrentItem;			///???
		return 1;
	}

	if (Xi_pCurrentItem->m_pLeft)
		FindItemByIdRecursive(Xi_pCurrentItem->m_pLeft, Xi_ppResultItem, Xi_Id);	///???
	if (Xi_pCurrentItem->m_pRight)
		FindItemByIdRecursive(Xi_pCurrentItem->m_pRight, Xi_ppResultItem, Xi_Id);		///???


	return 1;
}
//==================================//





