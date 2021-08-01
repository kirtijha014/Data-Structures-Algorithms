#include<iostream>
using namespace std;
class Fraction{
	public: 
	int numerator;
	int denominator;
	Fraction(int num,int den)
	{
		this->numerator = num;
		this->denominator = den;
	}
	void simplify()
	{
		int gcd = 1;
		int j = min(this->denominator,this->numerator);
		for(int i = 1; i <= j; i++)
		{
			if(numerator%i == 0 && denominator%i==0)
			{
				gcd = i;
			}
		}
		numerator = numerator/gcd;
		denominator = denominator/gcd;
	}
	
	Fraction& operator++()
	{
			numerator = numerator + denominator;
		simplify();
		return *this;
	}
	Fraction& operator++(int)
	{
		Fraction fnew(numerator,denominator);
		numerator = numerator + denominator;
		simplify();
		fnew.simplify();
		return fnew;
		
	}
	void display()
	{
		cout << numerator << " / "<< denominator <<endl;
	}
};

int main()
{
	Fraction f1(10,2);
	++f1;
	f1.display();
	f1++;
	f1.display();
	f1.display();
	(f1++)++;
	f1.display();
	
}
