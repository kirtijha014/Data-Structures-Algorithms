#include<iostream>
using namespace std;
int partition(int a[] , int start, int end)
{
	int pivot = a[start],p1 = start+1,i,temp;

	for(i=start+1;i<=end;i++)
	{	

		if(a[i]<pivot)
    	{	
    	cout<<"Before swap : "<<a[i]<<" ";
        	if(i!=p1)
      		{	  
            	temp=a[p1];
            	a[p1]=a[i];
            	a[i]=temp;
      		}
			  cout<<"after swap: "<<a[i]<<" "<<" i: "<<i<<" p1: "<<p1<<endl;    
			p1++;
    	}
	}	

        a[start]=a[p1-1];
        a[p1-1]=pivot;

	return p1-1;
}

void quick_sort(int arr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int part = partition(arr,start,end);
	quick_sort(arr,start, part-1);
	quick_sort(arr, part+1, end);
	
}
int main()
{
	int n;
	cout<<"Size : ";
	cin>>n;
	int arr[100];
	cout<<"\nElements : ";
	for(int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	int start = 0;
	int end  = n - 1;
	quick_sort(arr, start, end);
	cout<<"\nResult : ";
	for(int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
