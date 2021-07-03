#include<sys/time.h>
#include<iostream>

using namespace std;
long getTimeinMicroseconds()
{
	struct timeval start;
	gettimeofday(&start, NULL);
	return start.tv_sec * 1000000 + start.tv_usec;
}
void selectionsort(int arr[],int n)
{
	for(int i = 0; i < n-1; i++)
	{
		int min = arr[i];
		int pos = i;
		for(int j = i+1; j < n; j++)
		{
			if(arr[j] < min)
			{
				min = arr[j];
				pos = j;
			}
			int temp = arr[i];
			arr[i] = min;
			arr[pos] = temp;
		}
	}
}
int main()
{
	for(int n = 10; n <= 1000000; n*= 10)
	{
		int *arr = new int[n];
		long starttime, endtime;
		for(int i = 0; i < n; i++)
		{
			arr[i] = n-i;
		}
		starttime = getTimeinMicroseconds();
		selectionsort(arr,n);
		endtime = getTimeinMicroseconds();
		cout << "Selection Sort n = " << n << " time = " << endtime-starttime << endl;
	}
	
	return 0;
}

