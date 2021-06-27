#include<iostream>
using namespace std;
int SumOfDigits(int n)
{
	if(n<10)
	return n;
	int ans = n%10 + SumOfDigits(n/10);
	return ans;
}
int main()
{
	int n;
	cout<<"Enter Num: ";
	cin>>n;	
	cout<<"Sum of Digits: "<<SumOfDigits(n)<<endl;
	return 0;
}

