#include<iostream>
using namespace std;
#include "StudentClassWithName.cpp"

int main()
{
	char name[] = "Kirti";
	Student s1(20,name);
	s1.display();
	
	name[3] = 'e';
	Student s2(24,name);
	s2.display();
	s1.display();
	Student s3 = s1;
	s3.display();
	s1.display();
	return 0;
}
