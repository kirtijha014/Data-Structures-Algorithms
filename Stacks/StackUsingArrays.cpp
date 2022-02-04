#include<iostream>
using namespace std;
class Stack{
    int *data;
    int nextIndex;
    int capacity;
    public:
    Stack(int size)
    {
        capacity = size;
        data = new int[size];
        nextIndex = 0;
    }
    void push(int element)
    {
        if(nextIndex == capacity)
        {
            cout << "Stack is full.\n";
            return;
        }
        data[nextIndex] = element;
        cout << "\nPushed data " << data[nextIndex] << " into stack.\n";
        nextIndex ++;
        


    }
    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack is empty.\n";
            return INT_MIN;
            }
            
        nextIndex--;
        cout << "\nPopped :";
        return data[nextIndex]; 
    }
    int top()
    {
        if(isEmpty())
        {
            cout << "Stack is empty.\n";
            return INT_MIN;
            }
            
        return data[nextIndex - 1];
    }
    int size()
    {
        return nextIndex; // nextIndex will store the iteration.
    }
    bool isEmpty()
    {
        if(nextIndex == 0)
        return 1;
        else 
        return 0;
        //we can also write :
        //return nextIndex == 0 


    }
    void print()
    {
        cout << "\nThe stack :";
        for(int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
    }

};
int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    cout << s.pop() << " from the stack.\n";
    cout << " Top : " << s.top() << "\n";
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout << s.pop() << "from the stack.\n";
    cout << "Top : " << s.top() << "\n";
    s.print();
}