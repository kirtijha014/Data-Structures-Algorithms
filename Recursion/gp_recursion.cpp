#include<iostream>
#include<math.h>
using namespace std;
double sum(int n)
{
	if(n==0)
	return 1;
	double ans = 1 / (double)pow(2, n) + sum(n - 1); 
	return ans;
}
int main()
{
	int n;
	cin>>n;
	cout<<sum(n)<<endl;
	return 0;
}
