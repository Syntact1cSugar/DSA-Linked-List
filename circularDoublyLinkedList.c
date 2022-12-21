#include<stdio.h>
#include<stdlib.h>

struct Node
{
	char data;
	struct Node* next;
	struct Node* prev;
};
void display(struct Node* head)
{
	if(!head)return;
	struct Node* temp = head;
	do
	{
		printf("%c\t",temp->data);
		temp = temp->next;
	}
	while(temp!=head);
	printf("\n");
	return ;
}
struct Node* createNode(char data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = newNode->prev = NULL;
	return newNode;
}
struct Node* InsertFront(char data,struct Node* head)
{
	struct Node* newNode = createNode(data);
	newNode->data = data;
	if(!head)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		head = newNode;
	}
	else 
	{
		newNode->next = head;
		newNode->prev = head->prev;
		head->prev->next = newNode;
		head->prev = newNode;
		head = newNode;
	}
	return head;
}
struct Node* InsertRear(char data,struct Node* head)
{
	struct Node* newNode = createNode(data);
	if(!head)
	{
		head = newNode;
		head->next = head;
		head->prev = head;
	}
	else
	{	
		newNode->prev = head->prev;
		newNode->next = head;
		head->prev->next = newNode;
		head->prev = newNode;
	}
	return head;
}
int main()
{
	struct Node* head = NULL;
	int i;
	for(i=65;i<=72;i++)
		head = InsertRear((char)i,head);
	display(head);
	printf("i = %d\n",i);
	return 0;
}
