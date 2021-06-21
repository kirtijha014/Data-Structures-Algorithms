#include<iostream>
using namespace std;
int count_zeroes(int n)
{
	if(n == 0)
    {
		return 1;
    }
    if(n<10)
    {
        return 0;
    }
    else
    return count_zeroes(n/10)+count_zeroes(n%10);
}
int main()
{
	int n;
	cin>>n;
	cout<<"No. of Zeroes: "<<count_zeroes(n)<<endl;
	return 0;
	
}
