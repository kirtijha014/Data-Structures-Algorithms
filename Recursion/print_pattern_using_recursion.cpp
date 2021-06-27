// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
void pat(int n,vector<int>&ans){
if(n>0){
ans.push_back(n-5);
pat(n-5,ans);
}


}
    vector<int> pattern(int N){
        // code here
       vector<int>ans;
ans.push_back(N);
pat(N,ans);
int i=ans.size()-2;
for(;i>=0;i--){
ans.push_back(ans[i]);
        
    }
    return ans;
    }
};
int main(){
    int t;
    cout<<"test case:";
    cin>>t;
    while(t--){
        int N;
        cout<<"\n num: \n";
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
       cout<<"Pattern:";
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
       
    }
    return 0;
} 
