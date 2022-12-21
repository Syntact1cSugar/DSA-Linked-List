#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	struct Node *next,*prev;
	int data;
}
NODE;
typedef struct 
{
	struct Node *front,*rear;
	int count;
}
DEQUE;
DEQUE* CreateDeque()
{
	DEQUE* newD = malloc(sizeof(DEQUE));
	newD->front = newD->rear = NULL;
	newD->count = 0;
	return newD;
}
//Test State Operations
int isEmpty(DEQUE* D)
{
	return (D->front == NULL && D->rear == NULL)? 1 : 0;
}
int isFull(DEQUE* D)
{
	NODE* testP = malloc(sizeof(*(D->front)));
	if(!testP)return 1;
	else free(testP);
	return 0;
}
//Insert Operations 
int insertFront(DEQUE* D,int dataIn)
{
	if(isFull(D))return 0;
	NODE* newP = malloc(sizeof(NODE));
	newP->data = dataIn;
	newP->next = D->front;
	newP->prev = NULL;
	D->front = newP;
	if(D->rear == NULL) D->rear = newP;
	(D->count)++;
	return 1;
}
int insertRear(DEQUE* D,int dataIn)
{
	if(isFull(D))return 0;
	NODE* newP = malloc(sizeof(NODE));
	newP->data = dataIn;
	newP->next = NULL;
	if(D->rear)
		D->rear->next = newP;
	newP->prev = D->rear;
	D->rear = newP;
	if(!D->front)
		D->front = newP;
	(D->count)++;
	return 1;
}
//Delete Opeartions
int deleteFront(DEQUE* D)
{
	if(isEmpty(D))return 0;
	NODE* deleteP = D->front;
	D->front = D->front->next;
	if(D->count == 1) D->rear = NULL;
	else D->front->prev = NULL;
	free(deleteP);
	(D->count)--;
	return 1;
}
int deleteRear(DEQUE* D)
{
	if(isEmpty(D))return 0;
	NODE* deleteP = D->rear;
	D->rear = D->rear->prev;
	if(D->count == 1) D->front = NULL;
	else D->rear->next = NULL;
	free(deleteP);
	(D->count)--;
	return 1;
}
int getFront(DEQUE* D)
{
	if(isEmpty(D))return -1;
	return D->front->data;
}
int getRear(DEQUE* D)
{
	if(isEmpty(D))return -1;
	return D->rear->data;
}
//Miscellaneous Operations
int DisplayDeque(DEQUE* D)
{
	if(isEmpty(D))return 0;
	NODE* auxPtr = D->front;
	while(auxPtr)
	{
		printf("%d\t",auxPtr->data);
		auxPtr = auxPtr->next;
	}
	printf("\n");
	return 1;
}
int DequeCount(DEQUE* D)
{
	return D->count;
}
DEQUE* DeleteDeque(DEQUE* D)
{
	if(D)
	{
		while(D->front != NULL)
		{
			NODE* deleteP = D->front;
			D->front = D->front->next;
			free(deleteP);
		}
		D->front = D->rear = NULL;
		free(D);
	}
	return NULL;
}
int main()
{
	DEQUE* deque1 = CreateDeque();
	/**
	for(int i=1;i<=5;i++)
		insertRear(deque1,i);
		**/
	insertFront(deque1,79);
	DisplayDeque(deque1);
	deleteRear(deque1);
	DisplayDeque(deque1);
	deque1 = DeleteDeque(deque1);
	return 0;
}
