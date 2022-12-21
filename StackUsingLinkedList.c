#include<stdio.h>
#include<stdlib.h>


struct StackNode
{
	float data;
	struct StackNode* next;
};
void display(struct StackNode* top)//displaying from 0 to top index
{
	if(!top) return;
	display((*top).next);
	printf("%5.2f\t",(*top).data);
	return;
}
void Push(float data,struct StackNode** ptrToTop)
{
	struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
	newNode->data = data;
	newNode->next = *ptrToTop;
	*ptrToTop = newNode;
	return;
}
float Pop(struct StackNode** ptrToTop)
{
	struct StackNode* temp = *ptrToTop;
	float data = temp->data;
	*ptrToTop = (*(*ptrToTop)).next;
	free(temp);
	return data;
}
int main()
{
	struct StackNode* top = NULL;
	Push(1,&top);
	Push(2,&top);
	Push(3,&top);
	display(top);
	Pop(&top);
	printf("\n");
	display(top);
	return 0;
}
