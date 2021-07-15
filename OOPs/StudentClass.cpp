class Student{
	int age;
	public: 
	int roll;
	int getAge()
	{
		return age;
	}
	void setAge(int a)
	{
		if(a < 0)
		{
			cout << "Age cannot be less than zero.\n";
			return;
		}
		age = a;
	}
	void display()
	{
		cout << "Age : "<< age << " Roll : " << roll << endl; 
	}
};
