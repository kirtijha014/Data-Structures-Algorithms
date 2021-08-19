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
		Node* newnode = new Node (data);
		if(head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail -> next = newnode;
			tail =  tail -> next;
		}
		cin >> data;
	 } 
	 return head;
}

int length(Node* head)
{
	int count = 0;
	Node * temp = head;
	while(temp != NULL)
	{
		count ++;
		temp = temp -> next;
	}
	return count;
}

void print(Node * head)
{
	Node* temp = head;
	cout << "\nLinked List : ";
	while(temp != NULL)
	{
		cout << temp -> data << " ";
		temp =  temp -> next;
	}
	cout << endl;
}

int main()
{
	cout << "Enter List : ";
	Node * head = takeInput();
	int count = length(head);
	cout << "\nLength : " << count;
	print(head);
}
