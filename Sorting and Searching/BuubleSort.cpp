#include<iostream>
using namespace std;
void bubble_sort(int arr[], int n)
{
	for(int j = 0; j < n-1; j++)
	{
		for(int i = 0; i < n-1; i++)
		{
		if(arr[i]>arr[i+1])
		{
		int temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = temp;
		}
		}
		
	}	
	
}
int main()
{
	int n,i;
	cout<<"Enter size of the array: ";
	cin>>n;
	int *a = new int[n];
	cout << "\nEnter array elements: ";
	for(i =  0; i < n; i++)
	cin>>a[i];
	bubble_sort(a,n);
	cout << "\nThe sorted array is :";
	for(i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	delete []a;
	return 0;
}
