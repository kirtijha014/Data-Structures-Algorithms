#include<iostream>
using namespace std;
int binary_search(int a[],int num, int n)
{
	int start = 0;
	int end = n-1;
	
	while(start<=end)
	{
		int mid = (start + end)/2;
		if(a[mid] == num)
		{
			
		return mid;
		}
		else if(num<a[mid])
		{
			
			end = mid - 1;
		}
	 
		else
		start = mid + 1; 
	}
	return -1;
}

int main()
{
	int n;
	cout<<"Enter size of array: ";
	cin>>n;
	int *a = new int[n];
	cout<<"\nEnter elements of array: ";
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	int num;
	cout<<"\nEnter number to be found: ";
	cin>>num;
	int ans = binary_search(a,num,n);
	if(ans == -1)
	cout<<"\nNumber not found.\n";
	else
	cout<<"\nNumber found at index: "<<ans<<"\n";
	delete []a;
	return 0;
	
}
