#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Time: O(n)
    // Space: O(1)
    int maxSubArray(vector<int> &nums)
    {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = sol.maxSubArray(nums);

    return 0;
}