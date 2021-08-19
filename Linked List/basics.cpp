#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	
	//Constructor to enter data in Node
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
	
};
void print(Node*head)
	{
		//Creating a temporary variable for storing the value of head in order to save the value of our linked list
		Node *temp = head;
		while(temp != NULL)
		{
			cout << temp->data <<" ";
			temp = temp ->next;
		}
	}
int main()
{
	//Statically creating a Linked List
	
	 Node n1(1);
	 //Storing value of head(first node) as n1.
	 Node *head = &n1;
	 
	 Node n2(2);
	 Node n3(3);
	 Node n4(4);
	 Node n5(5);
	 n1.next = &n2;
	 n2.next = &n3;
	 n3.next = &n4;
	 n4.next = &n5;
	print (head);
	 /*
	 //Connecting both the nodes with each other(Storing address of n2 in n1)
	 n1.next = &n2;
	 
	 //Dynamically creating a Linked List
	 Node *n3 = new Node(10);
	 Node *head = n3;
	 Node *n4 = new Node(20);
	 
	 //Connection n3 and n4 with each other 
	 
	 n3->next = n4; //using -> as n3 is a pointer and not using &with n4 as n4 is a pointer and is already storing the address of the node n4. 
	 */
}

