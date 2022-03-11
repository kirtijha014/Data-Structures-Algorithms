#include<iostream>
using namespace std;

int sqrtInteger(int target)
{
    int start = 0, end = target;
    long long int ans = -1;
    while(start <= end)
    {
        long long int mid = (start + end) >> 1;
        long  long int square = mid * mid;

        if(target == square)
        return mid;
        else if(square < target)
        {
            ans = mid;
            start = mid + 1;
        }        
        else
        end = mid - 1;
    }
    return ans;
}

double morePrecision(int target, int precision, int tempSolution)
{
    double factor = 1;
    double ans = tempSolution;
    for(int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for(double j = ans; j * j < target; j= j + factor)
        {
            ans = j;
        }
    }
    return ans;
}



int main()
{
    int target;
    cin >> target;
    int tempSol = sqrtInteger(target);
    cout << "Answer is : " << morePrecision(target, 3, tempSol);
}