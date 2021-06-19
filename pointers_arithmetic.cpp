#include<iostream>

using namespace std;

int main()
{
	int i =10;
	int *p = &i;
	cout<<"p : "<<p<<endl;
	cout<<"*p : "<<*p<<endl;
	p++;
	cout<<"p++: "<<p<<endl;
	cout<<"*p++: "<<*p++<<endl;
	
	int arr[10];
	cout<<arr<<endl;
	cout<<&arr[0]<<endl;
	arr[0]=10;
	cout<<*arr<<endl;
	return 0;
	
}
