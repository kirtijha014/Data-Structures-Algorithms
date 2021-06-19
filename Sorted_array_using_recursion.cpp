#include<iostream>
using namespace std;
bool isSorted(int arr[], int n)
{
	if ( n == 0 || n == 1)
	{
		return true;
	}
	if(arr[0]>arr[1])
	return false;
	bool isSmallerOutput = isSorted(arr+1, n-1);
	cout<<*arr<<" ";
	return isSmallerOutput;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i <n ;i++)
	{
		cin>>arr[i];
	}
	
	cout<<"\n"<<isSorted(arr,n);
}
