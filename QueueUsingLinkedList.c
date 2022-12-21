#include<stdio.h>
#include<stdlib.h>

struct QueueNode
{
	char entry;
	struct QueueNode* link;
};
//front and rear poniters
struct QueueNode *front = NULL,*rear = NULL;
int isEmpty()
{
	return (!front && !rear)? 1 : 0;
}
void Display()
{
	struct QueueNode* auxPtr = front;
	while(auxPtr)
	{
		printf("%c\t",(*auxPtr).entry);
		auxPtr = (*auxPtr).link;
	}
	printf("\n");
	return;
}
void EnQueue(char entry)
{
	struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	(*newNode).link = NULL;
	(*newNode).entry = entry;
	if(!front)
		front = newNode;
	if(rear)
		(*rear).link = newNode;
	rear = newNode;
	return;
}
void DeQueue()
{
	if(isEmpty())return;
	if(front == rear)
	{
		free(front);
		front = rear = NULL;
		return;
	}
	struct QueueNode* targetNode = front;
	front = (*front).link;
	free(targetNode);
}
int main()
{
	int i;
	for(i=65;i<=72;i++)
		EnQueue((char)i);
	Display();
	for(i=0;i<=7;i++)
		DeQueue();
	Display();
	return 0;
}
