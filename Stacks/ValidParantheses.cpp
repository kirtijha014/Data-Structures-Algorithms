#include<iostream>
#include<stack>
using namespace std;

bool checkBalancedBrackets(stack<char>brackets, char ch)
{
    if(brackets.empty())
    return false;
    if(ch == ']' && brackets.top() != '[')
    if(ch == ')' && brackets.top() != '(')
    if(ch == '}' && brackets.top() != '{')
    {
        cout << ch << " and " << brackets.top()  << "are not valid.\n";
        return false;
    }

    return true;
}
bool isValid(string s)
{
    stack<char>brackets; 
    char temp;
    if(s.length()%2 != 0)
    return false;


    for(int i = 0; i < s.size(); i++)
    {
        temp = s[i];
        if(temp == '(' || temp == '[' || temp == '{')
            {
                cout << "Pushing" << temp << " into stack.\n";
                brackets.push(temp);
            }
        char x;
    switch (temp)
    {
    case ')':
        x = brackets.top();
        brackets.pop();
        if(x == '{' || x == '[')
        return false;
        break;
    case '}':
        x = brackets.top();
        brackets.pop();
        if(x == '(' || x == '[')
        return false;
        break;
    case ']':
        x = brackets.top();
        brackets.pop();
        if(x == '{' || x == '(')
        return false;
        break;
    }   
    }
    return true;

}

int main()
{
    string s;
    cin >> s;
    if(isValid(s) == 0)
    cout << "Not Valid.\n";
    else
    cout << "Valid.\n";

}