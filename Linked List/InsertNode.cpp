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
Node* takeInput()
{
	int data;
	cin >>  data;
	Node* head = NULL;
	Node* tail = NULL;
	while(data!= -1)
	{
		Node *newnode = new Node(data);
		if(head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = tail ->next;
		}
		cin >>  data;
	}
	return head;
}

Node* insert(Node* head, int position, int data)
{
	Node* newnode = new Node(data);
	int count = 0;
	Node *temp = head;
	//When position is 0 we have to update newnode's next to head and update the previous pointing head to newnode;
	if (position == 0)
	{
		newnode -> next = head;
		head = newnode;
		return head;
	}
	while(temp != NULL && count < position - 1)

	{
		temp = temp->next;
		count++;
		}	
		if(temp != NULL)
		{	
			newnode -> next = temp -> next; // Connecting Second part to the newnode
			temp -> next = newnode; //Connection first part to the newnode
			
		}
		else{
			cout << "Please insert correct position.\n";
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
	Node *head = takeInput();
	int n, num;
	cout << "Enter no. to be inserted : ";
	cin >> n;
	cout << "Index : ";
	cin>> num;
	head = insert(head,num,n);
	print(head);
}

