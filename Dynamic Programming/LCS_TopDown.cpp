#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int LCS_Top(string x, string y, int n, int m)
{
    int rows = n + 1, cols = m + 1;
    int dp[rows][cols];
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }    
    for(int i = 1 ; i < rows; i++)
    {
        for(int j = 1; j < cols; j++)
        {
            if(x[i-1] == y[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][m];
}
int main()
{
     string x, y;
    cout << "String 1 : " ;
    cin >> x;
    cout << "String 2 : ";
    cin >> y;
    int n = x.size();
    int m = y.size();
    int ans = LCS_Top(x,y,n,m);
    
    cout << "The longest Common Subsequence : " << ans << endl;
    return 0;
}