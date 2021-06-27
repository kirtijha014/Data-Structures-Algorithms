#include<iostream>
using namespace std;
int linear_search(int a[], int n, int num)
{
	if(a[0] == num)
	{
		return 0;
	}
	if( n == 1 && a[n] != num )
	return -1; 
	int ans = linear_search(a+1,n-1,num);
	if(ans == -1)
	return ans;
	else
	return ans+1;
}
int main()
{
	int n;
	cout<<"Enter size of array:";
	cin>>n;
	int *a= new int[n];
	cout<<"\nEnter elements in array:";
	for(int i = 0; i<n; i++)
	{
		cin>>a[i];
	} 
	int num;
	cout<<"\nEnter element to be searched:";
	cin>>num;
	int ans = linear_search(a,n,num);
	if(ans == -1)
	{
		cout<<"\nNumber not found"<<endl;
	}
	else
	{
		cout<<"\nNumber found at index: "<<ans<<endl;
	}
	
	delete []a;
	return 0;
}
