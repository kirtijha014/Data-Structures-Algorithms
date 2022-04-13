// Time Complexity : O(n*m)
//Space Complexity: O(n*m)

#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int LongestCommonSubstring(string x, string y,int n,int m)
{
    int maximum = 0;
    int dp[n+1][m+1];
    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < m+1; j++)
        {
            if(i == 0 || j == 0)
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++)
        {
            if(x[i-1] == y[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            dp[i][j] = 0;
        }
    }
    for(int i =0; i < n+1; i++)
    {
        for(int j = 0; j <m+1;j++)
        {
            maximum = max(maximum,dp[i][j]);
        }
    }
    return maximum;
}
int main()
{
    string x, y;
    cout << "Enter X : ";
    cin >> x;
    cout << "Enter Y : ";
    cin >> y;
    int n = x.size();
    int m = y.size();
    int ans = LongestCommonSubstring(x,y,n,m);
    cout << "Longest Common Substring : " << ans << endl;
    return 0;
}