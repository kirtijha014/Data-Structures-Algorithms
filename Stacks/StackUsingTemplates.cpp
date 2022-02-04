#include<iostream>
using namespace std;
template <typename T>
class Stack{
    T *data;
    int nextIndex;
    int capacity;
    public:
    Stack()
    {
        data = new int(capacity);
        nextIndex = 0;
    }
    void push(T element)
    {
        if(nextIndex == capacity)
        {
            T *newData = new T(2 * capacity);
            for(int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
        capacity = 2 * capacity;
        delete []data;
        data = newData;
        }
        data[nextIndex] = element;
        nextIndex += 1;

    }
    T pop()
    {
        if(isEmpty())
        {
            cout << "Stack is empty.\n";
            return INT_MIN;
        }
        nextIndex -= 1;
        return data[nextIndex];
    }
    T top()
    {
        return data[--nextIndex];
    }
    bool isEmpty()
    {
        if(nextIndex == -1)
        return 1;
        else
        return 0;
    }
    void print()
    {
        for(int i = 0 ;i <= nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
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
    s.push(6);
    s.push(7);
    cout << "Value popped "  << s.pop() << "\n";
    cout << "Top : " << s.top() << "\n";
    cout << "The stack : \n";
    s.print(); 

}