#include<iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end)
{
	//creating a temporary array
	//cout<<"start: "<<start<<" end: "<<end<<"\n";
	int temp[end - start + 1];
	int i = start , j = mid+1, k = 0;
	
	while(i <= mid && j <= end)
	{
		if (arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}
	while( i <= mid)
	{
		temp[k] = arr[i];
		k++; i++;
	}
	while( j <= end)
	{
		temp[k] = arr[j];
		k++; j++;
	}
	for(i = start; i <= end; i++)
	{
		arr[i] = temp[i-start];
	}
}
void merge_sort(int arr[], int start, int end)
{
	if(start >= end)
	return;
	int mid = (start + end)/2;
	
	 merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    cout<<"start: "<<start<<" end: "<<end<<"  mid: "<<mid<<"\n";
    merge(arr,start,mid,end);
}
int main()
{
	int n;
	cout<<"Size: ";
	cin>>n;
	int arr[100];
	cout<<"\nElements: ";
		if(n==0)
		{
			cout<<"0";
		}
	for(int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	int start = 0;
	int end = n - 1;
	merge_sort(arr,start,end);
	cout<<"\nResult: ";
	if(n==0)
		{
			cout<<"w0";
		}
	for(int i = 0; i < n; i++)
	{
		
		cout<<arr[i]<<" ";
	}

	cout<<endl;
	
	return 0;
}
