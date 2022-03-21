#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int activities;
    cin >> activities;
    vector<vector<int>> timeInterval;
    for(int i = 0; i < activities; i++)
    {
        int startTime, endTime;
        cin >> startTime >> endTime;
        timeInterval.push_back({startTime,endTime});
    }
    //sort(timeInterval.begin(), timeInterval.end());
}