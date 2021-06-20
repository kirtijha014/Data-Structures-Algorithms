#include<iostream>
using namespace std;
int power_recurse(int base, int power)
{
	if(power == 0)
	{
		return 1;
	}
	int ans =  base * power_recurse(base,power-1);
	return ans;
	
	
}

int main()
{
	int base;
	cout<<"Base: ";
	cin>>base;
	int power;
	cout<<"\nPower: ";
	cin>>power;
	cout<<"Result: "<<power_recurse(base,power)<<endl;
	
}
