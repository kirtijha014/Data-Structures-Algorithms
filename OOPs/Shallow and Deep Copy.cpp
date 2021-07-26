#include<iostream>
#include<cstring>
using namespace std;

class Student{
	int age;
	char *name;
	public:
		Student(int age,char*name)
		{
			this->age = age;
			//Shallow Copy: Copying the address of 0th element and not the whole array
			//this->name = name;
			
			
			
			//Deep Copy: Creating a new array yto copy the whole array
			this->name = new char[strlen(name)+1];
			strcpy(this->name,name);
		}
		
		
		void display()
		{
			cout<< "Name: "<< name <<" Age: "<< age <<endl;
		}
};
int main()
{
	char name[] = "Kirti";
	Student s1(20,name);
	s1.display();
	
	name[3] = 'e';
	Student s2(24,name);
	s2.display();
	s1.display();
	return 0;
}
