#include <iostream>
class Node
{
	public:
		int value;
		Node* next;
		Node(int value = 0, Node* next = NULL)
		{
			this->value = value;
			this->next  = next;
		}
};

Node* insert(Node* head, int value)
{
	Node* newP = new Node(value, head);
	return newP;
}
void PrintList(Node* head)
{
	while(head)
	{
		std::cout << head->value << '\t';
		head = head->next;
	}
	return;
}
//Reverse first k nodes from inital head
Node* reverse(Node* head, int k)
{
	if(k == 1)
	{
		return head;
	}
	Node* newHead 	 = reverse(head->next, k-1);
	Node* temp 	 = head->next->next;
	head->next->next = head;
	head->next       = temp;
	return newHead;
}
//Reverse List from left to right positions
Node* reverse(Node* head, int left, int right)
{
	if(left == 1)
	{
		return reverse(head, right);
	}
	head->next = reverse(head->next, left-1, right-1);
	return head;
}
int main()
{
	Node* head = NULL;
	for(int i=10;i>=1;i--)
	{
		head = insert(head, i);
	}
	PrintList(head);
	std::cout << '\n';
	head = reverse(head, 2, 7);
	PrintList(head);
	return 0;
}
