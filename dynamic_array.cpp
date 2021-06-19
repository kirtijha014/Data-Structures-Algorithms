#include<iostream>

using namespace std;

int main()
{
	int n ;
	cout<<"Enter Row  : ";
	cin>>n;
	cout<<endl;
	int m;
	cout<<"Enter Column : ";
	cin>>m;
	cout<<m;
	int **p = new int*[n];
	for(int i = 0; i < n; i++)
	{
		p[i] = new int [m];
		for(int j = 0 ;j < m; j++)
		cin>>p[i][j];
	 } 
	 
	 for(int i = 0; i < n; i++)
	{
		for(int j = 0 ;j < m; j++)
		cout<<p[i][j]<<" ";
	 } 
	 for(int j = 0 ;j < m; j++)
		delete []p[j];
		delete []p;
	 
}
