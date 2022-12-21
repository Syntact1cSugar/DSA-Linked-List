#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node* next;
	int data;
	struct Node* prev;
};
int NodeCount = 0;//to keep track of number of nodes in the list
void PrintList(struct Node* headerNode)
{
	if((*headerNode).next == NULL) return;
	struct Node* auxPtr = (*headerNode).next;
	while(auxPtr)
	{
		printf("%d\t",(*auxPtr).data);
		auxPtr = (*auxPtr).next;
	}
	printf("\n");
	return;
}
void PrintReverseList(struct Node* headerNode)
{
	if((*headerNode).next == NULL) return;
	struct Node* auxPtr = (*headerNode).next;
	while((*auxPtr).next != NULL)
		auxPtr = (*auxPtr).next;
	while(auxPtr != headerNode)
	{
		printf("%d\t",(*auxPtr).data);
		auxPtr = (*auxPtr).prev;
	}
	printf("\n");
	return;
}
void InsertFront(int data,struct Node* headerNode)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = data;
	(*newNode).next = (*headerNode).next;
	(*newNode).prev = headerNode;
	if((*headerNode).next != NULL)
		(*headerNode).next->prev = newNode;
	(*headerNode).next = newNode;
	NodeCount++;//Node inserted
	return;
}
void InsertRear(int data,struct Node* headerNode)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = data;
	(*newNode).next = (*newNode).prev = NULL;
	struct Node* auxPtr = headerNode;
	while((*auxPtr).next != NULL)//run this loop only if auxPtr->next is valid
		auxPtr = (*auxPtr).next;
	(*auxPtr).next = newNode;
	(*newNode).prev = auxPtr;
	NodeCount++;//Node inseerted
	return;
}
void DeleteFront(struct Node* headerNode)
{
	if((*headerNode).next == NULL)return;
	struct Node* auxPtr = (*headerNode).next;
	(*headerNode).next = (*auxPtr).next;
	if((*auxPtr).next != NULL)
		(*auxPtr).next->prev = headerNode;
	free(auxPtr);
	NodeCount--;//Node deleted
	return;
}
void DeleteRear(struct Node* headerNode)
{
	if((*headerNode).next == NULL)return;
	struct Node* auxPtr = (*headerNode).next;
	while((*auxPtr).next)
		auxPtr = (*auxPtr).next;
	(*auxPtr).prev->next = NULL;
	free(auxPtr);
	NodeCount--;
	return;
}
int main()
{
	//creation of special node called header node.
	struct Node* headerNode = (struct Node*)malloc(sizeof(struct Node));
	//setting the intial state of the header node.
	(*headerNode).data = NodeCount;//header node data holds global attribute of list
	(*headerNode).next = (*headerNode).prev = NULL;
	int i;
	for(i=1;i<=5;i++)
		InsertRear(i,headerNode);
	PrintList(headerNode);
	printf("Node count = %d\n",NodeCount);
	return 0;
}
