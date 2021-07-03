#include<iostream>
using namespace std;
void print_subsequence(string input, string output)
{
	if(input.empty())
	{
		cout << output <<" ";
		return;
	}
	print_subsequence(input.substr(1),output+input[0]);
	print_subsequence(input.substr(1),output);
	
}
int main()
{
	string input;
	cin >> input;
	string output = " ";
	cout << "Sub - Sequence: ";
	print_subsequence(input,output);
	return 0;
}
