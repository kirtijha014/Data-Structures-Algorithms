#include<iostream>
#include<climits>
using namespace std;
class Stack{
    int *data;
    int nextIndex;
    int capacity;
    public : 
    Stack()
    {

        data = new int(capacity);
        nextIndex = 0;
    }
    bool isEmpty()
    {
        if(nextIndex == -1)
        {
            return true;
        }
        else
        return false;
    }
    void push(int element)
    {
        if(nextIndex == capacity)
        {
            int *newData = new int(2* capacity);
            for(int i = 0; i < capacity; i++)
            {
                newData[i] = data[i]; 
            }
            capacity *= 2;
            delete []data;
            data = newData;
        }
            data[nextIndex] = element;
            nextIndex = nextIndex + 1;

    }
    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack is empty.\n";
            return INT_MIN;
        }

    }
    

};