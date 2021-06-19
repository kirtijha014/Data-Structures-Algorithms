#include<iostream>
using namespace std;
int main()
{
	int *p = new int;
	*p=10;
	cout<<*p<<endl;
	int *pa = new int[*p];
	for(int i = 0; i <*p;i++)
	{
		cin>>pa[i];
		
	}
	int max = -1;
	for(int i = 0; i <*p;i++)
	{
		if(max < pa[i])
		max = pa[i];
		cout<<pa[i]<<" ";
		
	}
	cout<<"\n Max: "<<max<<endl;
	return 0;
}
