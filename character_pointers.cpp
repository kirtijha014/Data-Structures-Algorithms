#include<iostream>

using namespace std;

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	char b[] = "abc";
	cout<<"a : "<<a<<endl;
	cout<<"b : "<<&b<<endl;
	char *c = &b[0];
	cout<<"c : "<<&c<<endl;
	char c1 = 'a';
	char *p = &c1;
	cout<<"p : "<<*p<<endl;
	return 0;
}
