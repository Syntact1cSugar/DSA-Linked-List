#include<stdio.h>
#include<stdlib.h>
//Date 9 March 2022 :(((((
struct PolynomialTerm
{
	struct PolynomialTerm* link;
	float coeffecient;
	int exponent;
};
void Insert(float coeffecientIn,int exponentIn,struct PolynomialTerm** ptrToRoot)
{
	struct PolynomialTerm* newTerm = malloc(sizeof(struct PolynomialTerm));
	(*newTerm).coeffecient = coeffecientIn;
	(*newTerm).exponent = exponentIn;
	(*newTerm).link = NULL;
	struct PolynomialTerm* auxPtr = *ptrToRoot;
	if(!auxPtr || exponentIn > (*auxPtr).exponent)//InsertFront
	{
		(*newTerm).link = *ptrToRoot;
		*ptrToRoot = newTerm;
		return;
	}
	while(auxPtr->link != NULL && auxPtr->link->exponent > exponentIn)
		auxPtr = (*auxPtr).link;
	(*newTerm).link = (*auxPtr).link;
	(*auxPtr).link = newTerm;
	return;
}
void PrintPolynomial(struct PolynomialTerm* first)
{
	if(!first)return;
	while(first)
	{
		printf("%+ 4.2fx^%d ",(*first).coeffecient,(*first).exponent);
		first = (*first).link;
	}
	printf("\n");
	return;
}
int main()
{
	struct PolynomialTerm* first = NULL;
	Insert(34,1,&first);
	Insert(5,0,&first);
	Insert(10,7,&first);
	Insert(-4,2,&first);
	Insert(8,5,&first);
	PrintPolynomial(first);
	return 0;
}
