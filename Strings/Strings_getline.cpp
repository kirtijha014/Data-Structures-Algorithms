#include<iostream>
using namespace std;
int main()
{
	//cin and getline cannot be used together.

	string s;
	//cin >> s;
	//cout << s << endl;
	string s1 = " ";
	getline(cin, s);
	getline(cin, s1);
	cout << s << " " << s1 << endl;
	
	//concatenate two strings.
	
	string s2 = s + s1;
	cout << s2 << endl;
	
	//size of string.
	
	cout << s2.size() << endl;
	
	//substring substr(3) it will print everything after 3rd index.
	
	cout << s2.substr(3) << endl;
	
	//substring substr(3,3) it will print everything after 3rd index till it prints 3 elements. 
	//This will have input as starting index and length
	
	cout << s2.substr(3, 3) << endl;
	
	//we can find substring using find function which will give us the index where it found the substring.(FIRST SUBSTRING)
	
	cout << s2.find("kir") << endl;
	
	return 0;
}
