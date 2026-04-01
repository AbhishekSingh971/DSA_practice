#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // time complexity: O(n)
    // space complexity: O(1)
    int searchInsert(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= target)
            {
                return i;
            }
        }
        return nums.size();
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