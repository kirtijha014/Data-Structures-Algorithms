#include<iostream>

using namespace std;

int main()
{
	int i = 10;
	int *p = &i;
	int **d = &p;
	int ***e = &d;
	cout<<"i : "<<i<<endl;
	cout<<"*p : "<<*p<<endl;
	cout<<"**d : "<<**d<<endl;
	return 0;
}
