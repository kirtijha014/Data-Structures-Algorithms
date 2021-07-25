#include<iostream>
using namespace std;
#include "StudentClass.cpp"


int main(){
	//Here default constructor would be called as compiler would interpret Student s1 = s1.Student() 
	Student s1;
	Student *s2 = new Student;
	//Parameterized Constructor, for p.constructor to be called we need to pass the argument in ().
	cout << "Parameterized Constructor: \n";
	Student s3(10);
	Student *s4 = new Student(10);
	return 0;
	
}
