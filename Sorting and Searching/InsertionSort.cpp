#include<iostream>
using namespace std;
void insertion_sort(int arr[], int n)
{
	for(int i = 0; i  < n; i++)
	{
		int current = arr[i],j;
		for(j = i -1 ; j >= 0; j--)
		{
			if(current < arr[j])
			{
				arr[j+1] = arr[j];
			}
			else{
				break;
			}
		}
		arr[j+1] = current;
	}
}
int main()
{
	int n;
	cout<<"Size: ";
	cin>>n;
	int arr[100];
	cout<<"\nElements: ";
	for(int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	insertion_sort(arr,n);
	cout<<"\nSorted array: ";
	for(int i = 0; i < n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
