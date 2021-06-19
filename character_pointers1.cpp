#include<iostream>
using namespace std;

int main()
{
	char a[]  = "hello";
	char *p = a ; 
	cout<<a[0]<<endl<< p[0] <<endl;
	char b = 'a';
	p = &b;
	b = b+1;
	cout<<(int)*p<<endl;
	char c[] = "xyz";
	p = &c[0];
	cout<<p<<endl;
	p++;
	cout<<p<<endl;
	return 0;
}
