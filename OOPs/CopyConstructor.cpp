#include<iostream>
using namespace std;
#include "StudentClass.cpp"

int main()
{
	Student s;
	Student s1(101);
	cout << "S1 : ";
	s1.setAge(20);
	s1.display();
	Student s2(s1);
	cout << "\nsS2 : ";
	s2.setAge(21);
	s2.display();
	
	Student *s3 = new Student(s2);
	cout << "\nS3 : ";
	s3->setAge(25);
	s3->display();
	
	Student s4(*s3);
	cout << "\nS4 : ";
	s4.setAge(29);
	s4.display();
	
	s4 = s1;
	cout << "\nS4 : ";
	s4.display();
	//using this delete keyword because s3 is a dynamically created object. Hence it will help destructor to identify s3 object and deallocate it.
	delete s3;
	return 0;
}
