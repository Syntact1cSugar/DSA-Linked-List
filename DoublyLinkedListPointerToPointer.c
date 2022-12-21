#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node* next;
	char data;
	struct Node* prev;
};
int isEmpty(struct Node* head)
{
	return (head == NULL)? 1 : 0;
}
void Print(struct Node* head)
{
	if(!head)
	{
		printf("\n");
		return;
	}
	printf("%c\t",(*head).data);
	return Print((*head).next);
}
void InsertFront(char data,struct Node** ptrToHead)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = data;
	(*newNode).next = *ptrToHead;
	(*newNode).prev = NULL;
	if(*ptrToHead != NULL)
		(*(*ptrToHead)).prev = newNode;
	*ptrToHead = newNode;
	return;
}
void InsertRear(char data,struct Node** ptrToHead)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	(*newNode).data = data;
	(*newNode).next = (*newNode).prev = NULL;
	if(*ptrToHead == NULL)
		return InsertFront(data,ptrToHead);
	struct Node* auxPtr = *ptrToHead;
	while((*auxPtr).next != NULL)
		auxPtr = (*auxPtr).next;
	(*newNode).prev = auxPtr;
	(*auxPtr).next = newNode;
	return;
}
void InsertPos(char data,int pos,struct Node** ptrToHead)
{
	if(pos == 1)
		return InsertFront(data,ptrToHead);
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->prev = newNode->next = NULL;
	struct Node* auxPtr = *ptrToHead;
	int i;
	for(i=0;i<pos-2;i++)
		auxPtr = (*auxPtr).next;
	(*newNode).next = (*auxPtr).next;
	if((*auxPtr).next != NULL)
		(*auxPtr).next->prev = newNode;
	(*newNode).prev = auxPtr;
	(*auxPtr).next = newNode;
	return;
}
void DeleteFront(struct Node** ptrToHead)
{
	if(isEmpty(*ptrToHead))return;
	struct Node* auxPtr = *ptrToHead;
	*ptrToHead = (*ptrToHead)->next;
	if(*ptrToHead != NULL)
		(*ptrToHead)->prev = NULL;
	free(auxPtr);
	return;
}

void DeleteRear(struct Node** ptrToHead)
{
	if(isEmpty(*ptrToHead))return;
	if((*ptrToHead)->next == NULL)
		return DeleteFront(ptrToHead);
	struct Node* auxPtr = *ptrToHead;
	while((*auxPtr).next != NULL)
		auxPtr = (*auxPtr).next;
	struct Node* antiRear = (*auxPtr).prev;
	(*antiRear).next = NULL;
	free(auxPtr);
	return;
}
void DeletePos(int pos,struct Node** ptrToHead)
{
	if(isEmpty(*ptrToHead))return;
	if(pos == 1)
		return DeleteFront(ptrToHead);
	struct Node* auxPtr = *ptrToHead;
	int i;
	for(i=0;i<pos-1;i++)
		auxPtr = (*auxPtr).next;
	(*auxPtr).prev->next = (*auxPtr).next;
	if((*auxPtr).next)
		(*auxPtr).next->prev = (*auxPtr).prev;
	free(auxPtr);
	return;
}
int main()
{
	struct Node* head = NULL;
	InsertRear('A',&head);
	InsertRear('B',&head);
	InsertRear('S',&head);
	Print(head);
	return 0;
}
