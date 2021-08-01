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
	
	Fraction& operator+=(Fraction const &f2){
		int lcm = denominator * f2.denominator;
		int x = lcm/denominator;
		int y = lcm/f2.denominator;
		int num = (x * numerator) + (y * f2.numerator);
		numerator = num;
		denominator = lcm;
		simplify();
		
	}
	void display()
	{
		cout << numerator << " / "<< denominator <<endl;
	}
};


int main()
{
	Fraction f1(1,2);
	Fraction f2(1,2);
	(f1 += f2) += f2;
	f1.display();
	return 0;
}
