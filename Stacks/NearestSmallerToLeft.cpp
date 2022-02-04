#include<bits/stdc++.h>
using namespace std;
vector<int> NearestSmallerToLeft(vector<int> arr, int n)
{
    stack <int> s;
    vector<int> v;
    for(int i = 0 ; i < n ; i++)
    {
        if(s.empty())
        v.push_back(-1);
        else if(s.size() > 0  && s.top() < arr[i])
        v.push_back(s.top());
        else if(s.size() > 0 && s.top() >= arr[i])
        {
            while(s.size() > 0 && s.top() >= arr[i])
            s.pop();
            if(s.size() == 0)
            v.push_back(-1);
            else
            v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    //reverse(v.begin(),v.end());
    return v;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = NearestSmallerToLeft(arr,n);
    for(int i : ans) cout << i << " ";
    cout << endl;

}