#include<iostream>
using namespace std;
void removeConsecutiveDuplicates(char *s)
{
	if (s[0]=='\0')
	{
		return;
	}
	if(s[0]==s[1])
	{
		int i = 0;
		while(s[i]!='\0')
		{
			s[i] = s[i+1];
			i++;
		}
		removeConsecutiveDuplicates(s);	
	}
	removeConsecutiveDuplicates(s+1);
}
int main()
{
	char s[100];
	cout<<"Enter String: ";
	cin>>s;
	cout<<endl;
	removeConsecutiveDuplicates(s);
	cout<<"Resultant String: "<<s<<endl;
	return 0;
}
