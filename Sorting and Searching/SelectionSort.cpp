#include<iostream>
using namespace std;
void selection_sort(int arr[], int n)
{
	//Find the min element in the array
	for(int i = 0; i < n-1; i++)
	{
		int min = arr[i], minindex = i;
		for(int j = i; j < n; j++)
		{
			if(arr[j] < min)
			{
				min = arr[j];
				minindex = j;
			}
			
			
		}
		//swapping the elements
		int temp = arr[i];
		arr[i] = arr[minindex];
		arr[minindex] = temp; 
		
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
	selection_sort(a,n);
	cout << "\nThe sorted array is :";
	for(i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	delete []a;
	return 0;
}
