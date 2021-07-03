#include<iostream>
#include<math.h>
using namespace std;
int subsequence(string input, string output[])
{
	if(input.empty())
	{
		output[0] = " ";
		return 1;
	}
	string substring = input.substr(1);
	int ans = subsequence(substring, output);
	for(int i = 0; i < ans; i++)
	{
		output[i+ans] = input[0] + output[i];
	}
	return 2 * ans;
	
}
int main()
{
	string s;
	getline(cin, s);
	int n = pow(2, s.size());
	string * output = new string[n];
	int count =	subsequence(s,output);
	cout<<"Subsequences: ";
	for(int i = 0; i < count; i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
}
