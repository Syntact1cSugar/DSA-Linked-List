#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	void *dataPtr;
	struct Node *next;
}
NODE;
NODE* InsertFront(void* dataPtrIn,NODE* Head)
{
	NODE* newP = (NODE*)malloc(sizeof(NODE));
	newP->dataPtr = dataPtrIn;
	newP->next = Head;
	Head = newP;
	return Head;
}
void PrintInt(void* dataPtr)
{	
	printf("%d",*((int*)dataPtr));
	return;
}
void PrintChar(void* dataPtr)
{
	printf("%c",*((char*)dataPtr));
	return;
}
void PrintFloat(void* dataPtr)
{
	printf("%-5.2f",*((float*)dataPtr));
	return;
}
int PrintList(NODE* Head,void (*ptrToPrint) (void*))
{
	if(!Head)return 0;
	while(Head!=NULL)
	{
		(*ptrToPrint)((*Head).dataPtr);
		printf("\t");
		Head = (*Head).next;
	}
	printf("\n");
	return 1;
}
int main()
{
	NODE* Head = NULL;
	float* a = (float*)malloc(sizeof(1));
	float* b = (float*)malloc(sizeof(1));
	float* c = (float*)malloc(sizeof(1));
	*a = 79.79;
	*b = 89.89;
	*c = 10.10;
	Head = InsertFront(a,Head);
	Head = InsertFront(b,Head);
	Head = InsertFront(c,Head);
	PrintList(Head,PrintFloat);
	return 0;
}
