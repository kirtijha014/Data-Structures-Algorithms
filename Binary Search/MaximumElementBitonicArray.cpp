#include<iostream>
using namespace std;
int maxBitonicArray(int *arr, int n)
{
    int start = 0,  end = n-1;
    while(start <= end)
    {
        int mid = (start + end) >> 1;
        if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        return arr[mid];
        else if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid +1])
        start = mid + 1;
        else if(arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
        end = mid - 1;
    }
    return -1;
}
int main()
{
    int n;
    cin >>n;
    int arr[n];
    for(int i = 0; i < n; i++)
    cin >> arr[i];
    cout << maxBitonicArray(arr,n);

}