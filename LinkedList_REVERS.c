#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


typedef struct  Node
{
	int data;
	struct Node* next;
}  Node, *pNode;

//pNode  Q1_2_1(pNode head);      // Call by value
void  Q1_2_2(pNode* pHead);    // Call by referance



//-------------------------------------------------------
pNode AddToEnd_1(pNode head)
{
	// Create new node
	pNode node_new = (pNode)malloc(sizeof(Node));
	node_new->data = rand() % RAND_MAX;
	node_new->next = NULL;

	// Link to end of linked list
	if (head == NULL)   // if LL  is empty
		head = node_new;
	else
	{
		pNode  p;
		for (p = head; p->next; p = p->next);
		p->next = node_new;
	}

	return head;
}
//-------------------------------------------------------

//-------------------------------------------------------
void Print(pNode head, char* str)
{
	pNode  p;
	printf("\n");
	puts(str);
	if (head == NULL)
	{
		printf("Empty list\n");
		return;
	}
	for (p = head; p->next; p = p->next)
		printf("%d--->", p->data);
	printf("%d\n", p->data);
}
//-------------------------------------------------------
void main()
{
	pNode head = NULL;


	srand(time(NULL));
	while (getche() == 'y')
	{
		head = AddToEnd_1(head);    // call by value

		Print(head, "Original list");
		head = Q1_2_1(head);
		//Q1_2_2(&head);
		Print(head, "Reverse list");

	}
	
	
	//---------------------------------------------------------------
	// General : 
	//            Reverse linked list    
	// Input:
	//         pHead - pointer to pointer to first node
	// Output:
	//         None
	void  Q1_2_2(pNode* pHead)    // Call by referance     Node** pHead
	{
		pNode p1 = *pHead, p2, p3 = NULL;
		while (p1)
		{
			p2 = p1->next;
			p1->next = p3;
			p3 = p1;
			p1 = p2;
		}
		*pHead = p3;   // head <-------  p3
	}

}
	
