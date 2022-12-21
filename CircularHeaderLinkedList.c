#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	struct Node* next;
	int data;
}
NODE;
NODE* CreateList()//Allocate memory for Header Node of type struct Node and intialize
{
	NODE* Head = (NODE*)malloc(sizeof(NODE));
	Head->data = -1;
	Head->next = Head;
	return Head;
}
int isEmpty(NODE* Head)
{
	return (Head->next == Head)? 1 : 0;
}
int isFull(NODE* Head)
{
	NODE* testP = (NODE*)malloc(sizeof(*(Head->next)));
	if(!testP)
		return 1;
	else free(testP);
	return 0;
}
//Insert Operations
int InsertFront(NODE* Head,int dataIn)
{
	if(isFull(Head))return 0;
	NODE* newP = (NODE*)malloc(sizeof(NODE));
	newP->data = dataIn;
	newP->next = Head->next;
	Head->next = newP;
	return 1;
}
int InsertRear(NODE* Head,int dataIn)
{
	if(isFull(Head))return 0;
	NODE* newP = (NODE*)malloc(sizeof(NODE));
	newP->data = dataIn;
	newP->next = Head;
	NODE* auxPtr = Head->next;
	while(auxPtr->next != Head)
		auxPtr = auxPtr->next;
	auxPtr->next = newP;
	return 1;
}
int InsertPos(NODE* Head,int dataIn,int pos)
{
	if(isFull(Head))return 0;
	NODE* newP = (NODE*)malloc(sizeof(NODE));
	newP->data = dataIn;
	newP->next = NULL;
	NODE* auxPtr = Head;
	for(int i=0;i<pos-1 && auxPtr->next != Head;i++)
		auxPtr = auxPtr->next;
	newP->next = auxPtr->next;
	auxPtr->next = newP;
	return 1;
}
//Delete Opearations
int DeleteFront(NODE* Head)
{
	if(isEmpty(Head))return 0;
	NODE* deleteP = Head->next;
	Head->next = Head->next->next;
	free(deleteP);
	return 1;
}
int DeleteRear(NODE* Head)
{
	if(isEmpty(Head))return 0;
	NODE* auxPtr = Head;
	while(auxPtr->next->next != Head)
		auxPtr = auxPtr->next;
	NODE* deleteP = auxPtr->next;
	free(deleteP);
	auxPtr->next = Head;
	return 1;
}
int DeletePos(NODE* Head,int pos)
{
	if(isEmpty(Head))return 0;
	NODE* auxPtr = Head;
	for(int i=0;i<pos-1 && auxPtr->next->next != Head;i++)
		auxPtr = auxPtr->next;
	NODE* deletePtr = auxPtr->next;
	auxPtr->next = deletePtr->next;
	free(deletePtr);
	return 1;
}
//Traverse Operation
int Traverse(NODE* Head)
{
	if(isEmpty(Head))return 0;
	NODE* auxPtr = Head->next;
	while(auxPtr != Head)
	{
		printf("%d\t",auxPtr->data);
		auxPtr = auxPtr->next;
	}
	printf("\n");
	return 1;
}
int main()
{
	NODE* Head = CreateList();
	InsertRear(Head,1);
	InsertRear(Head,2);
	InsertRear(Head,3);
	InsertFront(Head,69);
	Traverse(Head);
	DeletePos(Head,3);
	Traverse(Head);
	return 0;
}
