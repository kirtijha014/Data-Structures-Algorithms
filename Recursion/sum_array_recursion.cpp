#include<iostream>
using namespace std;

int sum(int input[], int size)
{ 
	if(size == 0)
	return 0;
	int small = input[0] sum(input+1, size-1);
	return small;
}
int main()
{
	int size;
	cin>>size;
	int *input = new int[size];
	for(int i = 0; i < size; i++) {
        cin >> input[i];
    }
    cout << sum(input, size) << endl;
	return 0;
}
