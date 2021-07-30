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
	//Function Overloading
	Fraction operator+(Fraction const &f2)
	{
		int lcm = denominator * f2.denominator;
		int x = lcm / this->denominator;
		int y = lcm / f2.denominator;
		
		int num = (x * numerator) + (y * f2.numerator);
		Fraction fadd(num,lcm);
		fadd.simplify();
		return fadd;
	}
	
	Fraction operator*(Fraction const &f2)
	{
		int num = numerator * f2.numerator;
		int den = denominator * f2.denominator;
		Fraction fmul(num,den);
		fmul.simplify();
		return fmul;
	}
	void display()
	{
		cout << numerator << " / "<< denominator <<endl;
	}
};


int main()
{
	Fraction f1(10,4);
	Fraction f2(10,2);
	Fraction f3 = f1 + f2;
	f1.display();
	f2.display();
	f3.display();
	Fraction f4 = f1 * f2;
	f4.display();
	f1.display();
	f2.display();
}
