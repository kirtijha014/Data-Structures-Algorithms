#include<iostream>
using namespace std;
#include "StudentClass.cpp"
int main()
{
	int a = 10;
	Student s1;
	s1.setAge(a);
	s1.roll = 101;
	cout << "Get age : " << s1.getAge() << endl;
	s1.display();
	return 0;
}
