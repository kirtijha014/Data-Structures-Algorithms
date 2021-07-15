#include<iostream>
using namespace std;
class Student{
	public : 
	int age;
	int rollNumber;
};

int main()
{
	Student s1;
	Student *s2 = new Student;
	s1.age = 24;
	s2-> age = 25;
	cout << s1.age  << endl;
	cout << s2-> age  <<endl;
	
	return 0;
}
