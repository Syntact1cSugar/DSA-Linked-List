#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int entry;
	int columnIndex;
	struct ListNode* next;
};
void Insert(int entry,int column,struct ListNode** first)
{
	struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
	(*newNode).entry = entry;
	(*newNode).columnIndex = column;
	(*newNode).next = NULL;
	if(*first == NULL)
	{
		*first = newNode;
		return;
	}

	struct ListNode* temp = *first;
	while(temp->next) temp = temp->next;
	(*temp).next = newNode;
	return;
}
void Display(struct ListNode* first)
{
	if(!first)return;
	while(first)
	{
		printf("Column:%d,Value:%d\t",(*first).columnIndex,(*first).entry);
		first = (*first).next;
	}
	printf("\n");
}
int main()
{
	int i,j,m=3,n=4;
	struct ListNode** List = (struct ListNode**)calloc(m,sizeof(struct ListNode*));
	int SparseMatrix[3][4] = {{0,0,0,1},{0,69,42,0},{420,0,0,10}};
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(SparseMatrix[i][j] != 0)
				Insert(SparseMatrix[i][j],j,List+i);
	for(i=0;i<m;i++)
		Display(*(List+i));
	return 0;
}
