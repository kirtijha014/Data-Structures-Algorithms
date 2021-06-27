#include<iostream>
using namespace std;
int all_indices(int arr[], int size, int num)
{
	int count = 0;
	if(arr[0]==num)
	{
		count++;
		return count;
	}
	if(size == 1 && arr[size]!=num)
	{
		return 0;
	}
	int ans = all_indices(arr+1,size-1,num);
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}
	int num;
	cout<<"Enter number: ";
	cin>>num;
	cout<<"\n"<<all_indices(arr,n,num);
}
