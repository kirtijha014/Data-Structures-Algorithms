#include<iostream>
using namespace std;
int last_index(int arr[],int size,int num)
{
	if(arr[size-1] == num)
	return size-1;
	
	if(size==1 && arr[size]!=num)
	return -1;
	int ans = last_index(arr+1,size-1,num);
	if(ans == -1)
	{
		if(arr[0]==num)
		return 0;
		return ans;
	}

	else
	return ans+1;
	
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
	
	cout<<"\n"<<last_index(arr,n,num);;

	
}
