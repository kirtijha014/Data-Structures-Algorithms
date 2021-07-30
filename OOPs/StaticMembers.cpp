#include<iostream>
using namespace std;

	

class Student{
	//Static Members
	static int totalStudents; //Total Number of Students Present
	public:
	int age;
	int roll;
	
	Student()
	{
		totalStudents++; //Inorder to update the value of the constructor
	}
	
	
	//Static Function
	static int getStudent()
	{
		return totalStudents;
	}
};
int Student :: totalStudents = 0; //Initializing the static property outside the class

int main()
{
	Student s1,s2,s3;
	s1.age = 21;
	s1.roll = 36;
	//cout << Student :: totalStudents << " " << s1.age << " " << s1.roll;
	
	cout << Student :: getStudent() << endl;
	return 0;
}
