#include<iostream>
#include<math.h>
using namespace std;
int knapsack(int totalWeight, int *value, int *weight, int size)
{
    if(totalWeight == 0 || size == 0)
    return 0;

    if(weight[size - 1] <= totalWeight)
    return max(value[])
}

int main()
{
    int size;
    cin >> size;
    int *value = new int(size);
    int *weight = new int(size);
    cout << "\nEnter value : ";
    for(int i = 0; i < size; i++)
    {
        cin >> value[i];
    }
    cout << "\nEnter weights : ";
    for(int i = 0; i < size; i++)
    {
        cin >> weight[i];
    }
    int totalWeight;
    cout << "\nTotal weight of the bag : ";
    cin >> totalWeight;
    int maxProfit = knapsack(totalWeight,value,weight,size);
    cout << "\nTotal maximum profit is : " << maxProfit << "\n";
    return 0;
}
