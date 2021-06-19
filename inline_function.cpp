#include<iostream>

using namespace std;

inline int f(int a , int b )
{
	cout<<"The Max  : ";
	return (a > b) ? a : b;
}
int main()
{
	int a,b;
	cout<<"Enter a and b : ";
	cin>>a>>b;
	cout<<endl;
	int c = f(a, b);
	cout<<c<<endl;
	return 0;
}
