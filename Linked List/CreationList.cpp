#include<iostream>
using namespace std;
class Node{
	public: 
	int data;
	Node *next;
	
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
	
};

// Time Complexity: O(n^2)
Node* takeInput()
{
	int data;
	cin >> data;
	Node* head = NULL;
	while(data != -1)
	{
		Node *newnode = new Node(data);
		if(head == NULL) //Inorder to only update the value of head once
		{
			head = newnode;
		}
		else
		{
			//establishing the connection between two nodes  
			Node* temp = head;
			while(temp -> next !=NULL) //it travel till the second last node as the last node would have Null, but temp will be pointing to the last node
									// we will set the value of temp->next = newnode
			{
				temp = temp->next;
			}
			temp -> next = newnode;
		}
		cin >> data;
	}
	return head;
}
 void print (Node* head)
 {
 	Node *temp = head;
 	cout<<"\nEntered List: ";
 	while(temp != NULL)
 	{
 		cout << temp->data << " ";
 		temp = temp->next;
	 }
	 cout<<endl;
 }


int main()
{
	cout << "Enter a list: ";
	Node *head = takeInput();
	print(head);
}
