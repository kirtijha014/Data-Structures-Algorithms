//Time Complexity : O(N) , where N is the size of the array
//Space Complexity : O(1), no extra space is required.

#include<iostream>
using namespace std;

int maxSubArraySum(int *array, int size)
{
    int currentSum = array[0];
    int overallSum = array[0];
    for(int i = 1; i < size; i++)
    {
        if(currentSum >= 0) //This will execute if the currentSum wil be greater than currentElement.
        {
            cout << "Current Sum  for : " << array[i] << " : " << currentSum << endl; 
            currentSum = currentSum + array[i];
        }
        else{
             cout << "Current Sum  for : " << array[i] << " : " << currentSum << endl; 
            currentSum = array[i];
        }
        if(currentSum > overallSum)
        {
            overallSum = currentSum;
             cout << "OVERALL SUM : " << array[i] << " : " << overallSum << endl; 
        }
    }
    return overallSum;

}
int main()
{
    int size;
    cin >> size;
    int *array = new int[size];
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    cout << "The maximum SubArray Sum :  " << maxSubArraySum(array,size);

}