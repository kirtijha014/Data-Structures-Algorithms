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
				tail -> next =  newnode;
				tail = tail -> next;
			}
			cin >> data;
		}
		return head;
}
Node* deleteTarget(Node* head, int target)
{
	Node* helper = new Node(0);
	helper -> next = head;
	Node * temp = helper;
	while(temp -> next != NULL)
	{
		if(temp -> next -> data == target)
		{
			Node* next = temp-> next;
			temp -> next = temp -> next -> next;
			
		}
		else
		temp = temp -> next;
	}
	return helper->next;
}

void print (Node * head)
{
	Node* temp =head;
	cout <<"\nLinked List: ";
	while(temp!= NULL)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

int main()
{
	cout << "Enter Linked List:  ";
	Node * head = takeInput();
	print(head);
	int target;
	cout << "\nDelete : ";
	cin >> target;
	head = deleteTarget(head,target);
	print(head);
	
}
