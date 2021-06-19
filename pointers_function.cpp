#include<iostream>
using namespace std;
void print(int *p)
{
	//cout<<"sizeof: "<<sizeof(a)<<endl;
	//cout<<"a[0] : "<<a[0]<<endl;
	int i = 10;
	p = &i;
	cout<<"p  in function :"<<p<<endl;
	*p = (*p)*(*p);
	cout<<"*p : "<<*p<<endl;
}
int main()
{
	int i = 10;
	print(&i);
	cout<<"&i : "<<&i<<endl;
	cout<<i<<endl; 
	//cout<<p<<endl;
	//int arr[]={1,2,3,4,5};
//	cout<<"size of : "<<sizeof(arr);
//	print(arr+1);
	//cout<<"arr[0]: "<<arr[0]<<endl;
	
	return 0;
	
}
