#include<iostream>
#include<string>
using namespace std;
char nextAlphabetElement(string arr,char target)
{
    int start = 0,  end = arr.size() - 1;
    char next = arr[0];
    while(start <= end)
    {
        int mid = (start + end) >> 1;
        if(target == arr[mid])
        {
            next = arr[mid] + 1;
            start = mid + 1;
        }
        else if(target > arr[mid])
        {
            start = mid + 1;
        }
        else
        end = mid -1;
    }
    return next;
}
int main()
{
    string arr;
    cin >> arr;
    char target;
    cin >> target;
   char ans = nextAlphabetElement(arr,target);
   cout << ans << " ";
}