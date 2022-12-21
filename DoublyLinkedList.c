#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *next,*prev;
	int data;
};
int isEmpty(struct Node* head)
{
	return (!head)? 1 : 0;
}
//Insert Operations
struct Node* insertFront(struct Node* head,int dataIn)
{
	struct Node* newP = (struct Node*)malloc(sizeof(struct Node));
	newP->data = dataIn;
	newP->prev = NULL;
	newP->next = head;
	if(head != NULL)
		head->prev = newP;
	head = newP;
	return head;
}
struct Node* insertRear(struct Node* head,int dataIn)
{
	struct Node* newP = (struct Node*)malloc(sizeof(struct Node));
	newP->data = dataIn;
	newP->next = newP->prev = NULL;
	struct Node* auxPtr = head;
	while(auxPtr && auxPtr->next)
		auxPtr = auxPtr->next;//Take to ultimate node
	newP->prev = auxPtr;
	if(auxPtr)
		auxPtr->next = newP;
	else 
		head = newP;
	return head;
}
struct Node* insertPos(struct Node* head,int dataIn,int pos)//pre = predecessor of target ndoe
{
	if(pos < 1)return head;
	struct Node* newP = (struct Node*)malloc(sizeof(struct Node));
	newP->data = dataIn;
	newP->next = newP->prev = NULL;//temporarily
	struct Node* pre = head;
	for(int i=0; pre != NULL && i<pos-2 && pre->next != NULL;i++)
		pre = pre->next;
	if(!pre)//No nodes in the list
		head = newP;
	else if(!pre->next || pos == 1)//Insertion at rear or front(pos-2<0) depending on pos
	{
		if(pos == 1)//Insert Front 
		{
			newP->prev = NULL;
			newP->next = pre;
			pre->prev = newP;
			head = newP;
		}
		else//Insert Rear since position is greater than number of nodes
		{
			pre->next = newP;
			newP->prev = pre;
			newP->next = NULL;
		}
	}
	else//Insertion somewhere in the middle(pos-2 > 0)
	{
		pre->next->prev = newP;
		newP->next = pre->next;
		newP->prev = pre;
		pre->next = newP;
	}
	return head;
}
//Delete Operation
struct Node* deleteFront(struct Node* head)
{
	if(isEmpty(head))return NULL;
	struct Node* deleteP = head;
	head = head->next;
	if(head)
		head->prev = NULL;
	free(deleteP);
	return head;
}
struct Node* deleteRear(struct Node* head)//pre = predecessor of target node
{
	if(isEmpty(head))return NULL;
	struct Node* pre = head;
	while(pre->next && pre->next->next)
		pre = pre->next;//Take to the penultimate node
	if(pre->next)
	{
		free(pre->next);
		pre->next = NULL;
	}
	else//only one node in the list
	{
		free(pre);
		head = NULL;
	}
	return head;
}
struct Node* deletePos(struct Node* head,int pos)//pre = predecessor of target node
{
	if(isEmpty(head))return NULL;
	if(pos < 1)return head;
	struct Node* pre = head,*deleteP = NULL;
	for(int i=0; pre->next != NULL && i<pos-2 && pre->next->next != NULL;i++)
		pre = pre->next;
	if(!pre->next || pos == 1)//Only one node in the list or position is 1(one or more nodes)
	{
		deleteP = pre;
		head = head->next;
		if(head)head->prev = NULL;//If there was more than one node in the list
		free(deleteP);
	}
	else if(!pre->next->next)//Implies the position is greater than the number of nodes
	{
		deleteP = pre->next;
		pre->next = NULL;
		free(deleteP);	
	}
	else//Somwhere in the middle
	{
		deleteP = pre->next;
		pre->next = deleteP->next;
		deleteP->next->prev = pre;
		free(deleteP);
	}
	return head;
}
//Traverse Operations
int printList(struct Node* head)
{
	if(isEmpty(head))return 0;
	while(head)
	{
		printf("%d\t",head->data);
		head = head->next;
	}
	printf("\n");
	return 1;
}
int main()
{
	struct Node* head = NULL;//Hold the reference of first node in the list
	for(int i=1;i<=5;i++)
		head = insertRear(head,i);
	printList(head);
	head = deletePos(head,1);
	printList(head);
	return 0;
}
