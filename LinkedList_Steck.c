#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENTH 10

typedef struct  node
{
	int num;
	struct node* next;


}  Node;




//-------------------------------------------------------
void Add_Head(Node** pHead, int num)
{
	Node *p;
	Node* new_node = (Node*)malloc(sizeof(Node)); /* allocate memory */
	if (*pHead == NULL)
	{  //  Empty list
		*pHead = new_node;
	}
	else
	{
		
     new_node->num = num; /* assign data element */
	new_node->next = *pHead;
	*pHead = new_node;
	}
	
	
	
}

void GetFromHead(Node** pHead)
{
	Node *p;
	p = *pHead;
	*pHead = *pHead->next;
	

}