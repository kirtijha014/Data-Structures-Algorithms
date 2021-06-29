#include<iostream>
using namespace std;
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void bubble_sort(int arr[], int n)
{
	for (int i = 0; i< n-1; i++)
	{
		bool swapped;
		for(int j = 0; j < n-i-1; j++)
		{
			swapped = false;
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				swapped = true;
			}
		}
		if(swapped ==  false)
		break;
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
