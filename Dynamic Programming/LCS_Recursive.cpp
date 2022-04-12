#include<iostream>
#include<string>
using namespace std;
int LongestCommonSubSequence(string x, string y, int n, int m)
{
    if(n == 0 || m == 0)
    return 0;
    if(x[n-1] == y[m-1])
    {
        return 1 + LongestCommonSubSequence(x,y,n-1,m-1);
    }
    else
    {
        return max(LongestCommonSubSequence(x,y,n-1,m),LongestCommonSubSequence(x,y,n,m-1));
    }

}
int main()
{
    string x, y;
    cout << "X : ";
    cin >> x;
    cout << "\nY : ";
    cin >> y;
    int n = x.size();
    int m = y.size();

    int lcs = LongestCommonSubSequence(x,y,n,m);
    cout << "The longest common subsequence is " << lcs << endl;

    return 0;
}