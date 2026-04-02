#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // time complexity: O(n)
    // space complexity: O(1)
    // int searchInsert(vector<int> &nums, int target)
    // {
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         if (nums[i] >= target)
    //         {
    //             return i;
    //         }
    //     }
    //     return nums.size();
    // }

    // Optimal Approach: Binary Search
    // Time Complexity: O(log n)
    // Space Complexity: O(1)
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};

int main()
{
    Solution sol;
    vector nums = {1, 3, 5, 6};
    int target = 5;

    int result = sol.searchInsert(nums, target);
    cout << "searchInsert : " << result << endl;

    return 0;
}