#include<iostream>
using namespace std;
int fib(int n)
{
	int output1 = 0;
	int output2 = 0;
	if(n == 0)
	{
		return 0;
		
	}
	if(n == 1)
	{
		return 1;
	}

	output1 = fib(n-1);
	cout<<"output1: "<<output1<<"  ";
	output2 = fib(n-2); 
	cout<<"output2: "<<output2<<"   ";
	//cout<<""<<output1+output2<<" ";
	return output1+output2;
}
int main()
{
	int n;
	cin>>n;
	cout<<endl<<fib(n);
}
