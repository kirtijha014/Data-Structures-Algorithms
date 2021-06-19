#include<iostream>

using namespace std;

void func(int& r)
{
	
 r++;

}

int main()
{
	
	int  i = 0;
	int& j = i;

	cout << j << endl;
	
	 func(i);
	
	cout << i << endl;
	
	return 0;
}
