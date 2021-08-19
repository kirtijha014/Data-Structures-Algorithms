#include<iostream>
using namespace std;
class Node{
	public: 
	int data;
	Node* next;
	
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

//Time Complexity : O(n)
Node* takeInput_Better(){
	int data;
	cin>>data;

	Node* head = NULL;
	Node* tail = NULL;
	while(data != -1)
	{
			Node* newnode =  new Node(data);
		if(head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail -> next = newnode;
			tail = tail -> next; //Or we can write tail = newnode; Here we are updating the value of tail from previous node to newnode
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	cout << "\n Entered List: ";
	while(temp != NULL)
	{
		
		cout << temp->data << " ";
		temp = temp ->next;
	}
	cout << endl;
}

int main()
{
	cout << "enter list: ";
	Node * head = takeInput_Better();
	print(head);
}
