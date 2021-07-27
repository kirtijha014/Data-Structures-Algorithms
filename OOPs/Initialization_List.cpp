
#include<iostream>
#include<cstring>
using namespace std;


class Student{
	public:
		int age;
		const int roll;
		char *name;
		
		
		//Initialization list: We can also use non-const values.
		Student(int r): roll(r){
			
			//We can also do:Student(int r, int a): roll(r),age(a){}
			
			// For reference variables:
			// Student(int r, int a ): roll(r),age(a), x(this->age)//Here x this the reference variable for age. &x = age;
			 
		}
		
		
	//
};


int main()
{
	Student s1(101);
	s1.age = 10;
	//s1.name("Kirti");
	cout << "Age: "  << s1.age << " RollNo.: " << s1.roll <<endl;
}
