#include<iostream>
using namespace std;
template <typename T>
class Node{
public:
    T data;
    Node <T>* next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename T> 
class Stack{
    Node<T>* head;
    int size;
    public:
    Stack()
    {
        head =  NULL;
        size = 0;
    }
    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++; 

    }
    T top()
    {
        if(isEmpty())
        {
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        return head->data;
    }
    T pop()
    {
        if(isEmpty())
        {
            cout << "Stack is empty\n";
            return INT_MIN;
        }
        T ans = head -> data;
        Node<T> *temp = head;
        head= head->next;
        delete temp;
        size--;
        return ans;


    }
    T StackSize()
    {
        return size;
    }
    bool isEmpty()
    {
        if(head == NULL)
        return true;
        else
        return false;
    }
    void print()
    {
        Node<T> *temp = head;
        while(temp != NULL)
        {
            cout << temp -> data << " ";
            temp = temp->next;
        }
    }

};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Popped value : " << s.pop() << endl;
    cout << "Top Value : " << s.top() << endl;
    cout << "Size of stack : " << s.StackSize() << endl;
    cout << "The stack : \n";
    s.print();
}