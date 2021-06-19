#include<iostream>
using namespace std;
int a;
int g()
{
	a++;
	cout<<"a in g() : "<<a<<endl;
}
int f()
{
	a++;
	cout<<"a in f() : "<<a<<endl;
	g();
}
int main()
{
	a = 10;
	f();
	cout<<"a in main : "<<a;
	
	return 0;
}
