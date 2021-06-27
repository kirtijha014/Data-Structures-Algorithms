#include<iostream>
using namespace std;
int length(char input[])
{
	int len = 0;
	for(int i = 0; input[i] != '\0';i++)
	{
		len++;
	}
	return len;
}
bool palindrome(char input[],int start,int end)
{
	if(start == end)
	{
		return true;
	}
	if(input[start]!= input[end])
	return false;
	if(start<end)
	return palindrome(input,start+1,end-1);
		return true;
}
bool isPalindrome(char input[])
{
	int len = length(input);
	if(len == 0)
	return true;
	return palindrome(input,0,len-1);
}
int main()
{
	char input[50];
	cout<<"Enter String:";
	cin>>input;
	cout<<endl;
	if(isPalindrome(input))
	{
		cout<<"True"<<endl;
	}
	else
	cout<<"False"<<endl;
	return 0;
}
