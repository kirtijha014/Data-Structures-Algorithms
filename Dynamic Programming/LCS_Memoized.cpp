#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int dp[1001][1001] = {-1}; 
int LCS_Mem(string x, string y, int n, int m)
{
   if(n == 0 || m == 0)
    return 0;
    if(dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if(x[n-1] == y[m-1])
    {
        dp[n][m] = 1 + LCS_Mem(x,y,n-1,m-1);
        return dp[n][m];
    }
    else
    {
       dp[n][m] = max(LCS_Mem(x,y,n-1,m),LCS_Mem(x,y,n,m-1));
       return dp[n][m];
    }
    
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
    // memset(dp,-1,sizeof(dp));
    int ans = LCS_Mem(x,y,n,m);
    
    cout << "The longest Common Subsequence : " << ans << endl;
    return 0;
}