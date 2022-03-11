#include<iostream>
#include<math.h>
using namespace std;
int minimumDifference(int *arr, int size, int target)
{
    int start = 0 , end = size - 1;
    while(start <= end)
    {
        int mid = (start + end) >> 1;
        if(target == arr[mid])
        {
            //cout << "arr[mid : " << mid <<" ] :" <<arr[mid];
            return arr[mid];
        }
        else if(target < arr[mid])
        {
            //cout << "arr[end : " << end <<" ] :" <<arr[end];
            end = mid - 1;
        }
        else{
            //cout << "arr[start : " << start <<" ] :" <<arr[mid];
            start = mid + 1;
        }
    }
    int minStart = abs(arr[start] - target);
    int minEnd = abs(arr[end] - target);
    if(minStart < minEnd)
    return arr[start];
    else 
    return arr[end];

}
int main()
{
    int size;
    cin >> size;
    int *arr = new int(size);
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    int result = minimumDifference(arr, size,target);
    cout << result;


}