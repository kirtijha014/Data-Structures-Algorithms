// Time Complexity = O(log n)
//Space Complexity = O(1)

#include<iostream>
#include<vector>
using namespace std;

 int peakElementIndex(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if ((mid == 0 || nums[mid] >= nums[mid - 1]) && 
            (mid == nums.size() - 1 || nums[mid] >= nums[mid + 1])) {
            return mid;
        }
        
        if (mid < nums.size()- 1 && nums[mid] <= nums[mid + 1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
    }



int main()
{
    int size = 7;
    vector<int>array(size);
    for(int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "The index of peak element is : " << peakElementIndex(array);

}