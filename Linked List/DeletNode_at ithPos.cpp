#include<iostream>
using namespace std;
class Node{
	public:  
	int data;
	Node* next;
	Node(int data)
	{
		this -> data = data;
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
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail -> next = newnode;
			tail = tail -> next;
		}
		cin >> data;
	}
	return head;
}

Node* deleteNode(Node* head, int position)
{
	int count = 0;
	Node* temp = head;
	if(position == 0)
	{
		head = head->next;
		return head;
	}
	while(temp != NULL && count < position-1)
	{
		temp = temp ->next;
		count++;
	}
	if(temp != NULL)
	{
		temp ->  next = temp->next->next;
	}
		
		return head;
}

void print(Node* head)
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

int main()
{
		cout << "Enter linked List :";
	Node* head = takeInput();
	print(head);
	
	int pos;
	cout << "\nEnter position to deleted: ";
	cin >> pos;
	
	head = deleteNode(head,pos);
	print(head);
	
}

	

