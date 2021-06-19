#include<iostream>
using namespace std;
int main()
{
	int const i = 10;
	
	int const &j = i;
	int k =10;
	int const &j2 = k;
	cout<<j<<endl;
	cout<<i<<endl;
	k++;
	cout<<j2<<endl;
	
}
