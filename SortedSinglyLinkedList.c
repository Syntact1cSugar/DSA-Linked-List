#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node* next;
	int data;	
};
struct Node* Insert(int dataIn,struct Node* first)
{
	struct Node* newP = (struct Node*)malloc(sizeof(struct Node));		
	newP->data = dataIn;
	newP->next = NULL;//Temporarily
	if(!first || first->data >= dataIn)//Insert Front
	{	
		newP->next = first;
		first = newP;
		return first;
	}
	struct Node* auxPtr = first;
	while(auxPtr->next && auxPtr->next->data < dataIn)//Find suitable Predessecor Node
		auxPtr = auxPtr->next;
	newP->next = auxPtr->next;
	auxPtr->next = newP;
	return first;
}
		
int Print(struct Node* first)
{
	if(!first)return 0;
	while(first)
	{
		printf("%d\t",first->data);
		first = first->next;
	}
	printf("\n");
	return 1;
}
int main()
{
	struct Node* first = NULL;
	first = Insert(3,first);
	first = Insert(78,first);
	first = Insert(-1,first);
	first = Insert(100,first);
	first = Insert(87,first);
	first = Insert(73,first);
	first = Insert(8999,first);
	Print(first);
	return 0;
}
