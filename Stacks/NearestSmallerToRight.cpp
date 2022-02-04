#include<bits/stdc++.h>
using namespace std;
vector<int> NearestSmallerToRight(int *arr, int n)
{
    stack<int> s;
    vector<int> v;
    for(int i = n-1; i >= 0; i--)
    {
        if(s.empty())
        v.push_back(-1);
        else if(s.size()> 0 && s.top() < arr[i])
        {
            v.push_back(s.top());
        }
        else if(s.size() > 0  && s.top() >= arr[i]) 
        {
            while(s.size() > 0 && s.top() >= arr[i])
            {
                
            }
        }
    }

}
int main()
{
    int n;
    cin >> n;
    int *arr =new int(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = NearestSmallerToRight(arr,n);
    for(int i : ans) cout << i << " ";
    cout << endl;
}






