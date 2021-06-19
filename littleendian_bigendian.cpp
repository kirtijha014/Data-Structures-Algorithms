#include<iostream>
using namespace std;


int main()
{
	unsigned int i = 1;
	char *p = (char*)&i;
	if(*p)
	{
		cout<<"Little Endian."<<*p;
	}
	else
	cout<<"Big Endian.";
	
	int arr[5] = {1,2,3,4,5};
	int *pc = arr;
	for(int i =0;i<5;i++)
	{
		cout<<arr[1]<<" ";
		*pc++;
	}
	return 0;
	
}
