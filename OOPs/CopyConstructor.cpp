#include<iostream>
using namespace std;
#include "StudentClass.cpp"

int main()
{
	Student s1(101);
	Student s2(s1);
	s2.display();
	return 0;
}
