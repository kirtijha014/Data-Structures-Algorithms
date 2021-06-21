#include<iostream>
using namespace std;
int multiply(int m, int n)
{
	if(n>m)
	{
		
		return multiply(n,m);
		
	}
	if(m == 0 || n== 0)
	{
		return 0;
	}
	return m +  multiply(m,n-1);
	
	
}
int main()
{
	int m,n;
	cin>>m>>n;
	int ans = multiply(m,n);
	cout<<"result: "<<ans<<endl;
	return 0;
}
