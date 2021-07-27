#include<cstring>
class Student{
	int age;

	public:
			char *name;
		Student(int age,char*name)
		{
			this->age = age;
			//Shallow Copy: Copying the address of 0th element and not the whole array
			//this->name = name;
			
			
			
			//Deep Copy: Creating a new array yto copy the whole array
			this->name = new char[strlen(name)+1];
			strcpy(this->name,name);
		}
		
		
		
		//Copy COnstructor " Inbuilt copy constructor uses shallow copy
		//Calling parameterized Cpy Constructor
		Student (Student const &s)
		{
			//How does Inbuilt copy constructor do Shallow Copying?
			
			//this->name = s.name;
			this->age = s.age;
			//We have to avoid doing Shallow Copy
			
			//How to perform Deep Copy in Copy Constructor
			this->name=new char[strlen(name)+1];
			strcpy(this->name,s.name);
		}
		
		
		void display()
		{
			cout<< "Name: "<< name <<" Age: "<< age <<endl;
		}
};
