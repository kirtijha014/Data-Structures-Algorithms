// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int binarysearch(int arr[], int num, int start, int end)
{
    int mid = (start + end)/2;
    if(start>end)
    {
        return -1;
    }
    if(arr[mid]==num)
    return mid;
    else if(num < arr[mid])
    {
        return binarysearch(arr, num, start,mid-1);
    }
    else
    return binarysearch(arr, num, mid + 1, end);
    
}
int main() {
    // Write C++ code here
    int n,i;
    cout<<"Enter size: ";
    cin>>n;
    int *a = new int[n];
    cout<<"\n Enter elements: ";
    for(i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int t,num;
    int start = 0, end = n-1,ans;
    cout<<"Enter test case: ";
    cin>>t;
    while(t--)
    {
        cout<<"\nEnter num: ";
        cin>>num;
        ans = binarysearch(a, num, start,end);
        cout<<"\nAns:"<<ans;
        
    }
    
    
   

    return 0;
}
