#include<iostream>
using namespace std;

int first_index(int arr[], int size,int num)
{
	if(arr[0]==num)
	{
		cout<<"returning this val\n";
		return 0;
	}
		if(size==1 && arr[size]!=num)
	{
		return -1;
	}
	int smallOutput = first_index(arr+1, size-1, num);
	if (smallOutput==-1)
	return smallOutput;
	else
	return smallOutput+1; 
}

int main()
{
	int size;
	cin>>size;
	int arr[size];
	int num;
	for(int i = 0; i<size; i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter number to be searched:\n";
	cin>>num;
		
	cout<<"\n"<<first_index(arr,size,num);	
}
