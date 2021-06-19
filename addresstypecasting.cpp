#include<iostream>
using namespace std;
int main()
{
	int i = 65;
	char c = i;
	cout<<"C: "<<c<<endl;
	int *pi = &i;
	char *pc = (char*)pi;
	cout<<"*pi: "<<*pi<<endl; 	
	cout<<"*pc : "<<*pc<<endl; 	
	cout<<"*(pc+1) : "<<*(pc+1)<<endl; 	
	cout<<"*(pc+2) : "<<*(pc+2)<<endl; 	
	cout<<"*(pc+3) : "<<*(pc+3)<<endl; 	
	char b = 'A';
	int a = b;
	cout<<"int a : "<<a<<" char b : "<<b<<endl;
	char *p = &b;
	int *point = (int*) &b;
	cout<<"*point : "<<*(point)<<endl;
	cout<<"p : "<<p<<endl;
	
	
	
}
