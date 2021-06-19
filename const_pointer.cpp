#include<iostream>
using namespace std;
int main()
{
	int i =10;
	int j = 12;
	int const *p = &i;
	p = &j;
	cout<<"*p : "<<*p;
	cout<<"\n p : "<<p<<endl;
	int * const p1 = &i;
	p1 = &j;
}
