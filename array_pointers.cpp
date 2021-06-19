#include<iostream>

using namespace std;

int main()
{
	int a[10];
	cout<<"a: "<<a<<"\n";
	
	 a[0] = 5;
	 a[1] = 10;
	 cout<<a+2<<endl;
	// cout<<"*a : "<<*a<<"\n";
	// cout<<"*(a+1) : "<<*(a+1)<<"\n";
	 //int i =2;
	 //i[a]= 15;
	 //cout<<"i[a] : "<<i[a]<<"\n";
	 int *p = a;
	 //cout<<"Size of a: "<<sizeof(a)<<endl<<"Size of p : "<<sizeof(p)<<endl;
	 //cout<<"&a : "<<&a<<endl<<" &p : "<<&p<<endl;
	 //a[0]= a[1]+3;
	 //cout<<"a= a+3 : "<<a++<<endl;
	// p = a+3;
	 //cout<<"p = a+3 : "<<p<<endl;
	 cout<<*p <<endl;
 	return 0;
}
