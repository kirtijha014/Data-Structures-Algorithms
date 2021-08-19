#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int data)
		{
			this->data  = data;
			this -> next = NULL;
		}
};

Node* takeInput()
{
	int data;
	cin >> data;
	Node* head = NULL;
	Node* tail = NULL;
	while(data != -1)
	{
		Node* newnode = new Node(data);
		if(head == NULL)
		{
			head =  newnode;
			tail = newnode;
		}
		else
		{
			tail -> next = newnode;
			tail = tail->next;
		}
		cin>> data;
	}
	return head;
}
void mid(Node* head)
{
	int length = 0;
	Node * mid = head;
	while(head != NULL)
	{
		if(length & 1)
		mid = mid -> next;
		length++;
		head = head -> next;
		
	}
	
	if(mid!= NULL)
	{
		cout << mid -> data <<"\n";
	}
}
void print(Node* head)
{
	Node* temp =head;
	cout << "\n Linked List: ";
	while(temp!= NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

int main()
{
	Node * head = takeInput();
	print(head);
	cout << "\nMid : ";
	 mid(head);
	
}
