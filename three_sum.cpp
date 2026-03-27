#include <vector>
#include <set>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
    // public:
    // hash set approach
    // Time: O(n²)
    // Space: O(n)
    //     vector<vector<int>> threeSum(vector<int>& nums, int target) {
    //         set<vector<int>> unique;   // to avoid duplicates
    //         int n = nums.size();

    //         for (int i = 0; i < n; i++) {
    //             unordered_set<int> seen;

    //             for (int j = i + 1; j < n; j++) {
    //                 int needed = target - nums[i] - nums[j];

    //                 if (seen.count(needed)) {
    //                     vector<int> triplet = {nums[i], nums[j], needed};
    //                     sort(triplet.begin(), triplet.end());
    //                     unique.insert(triplet);
    //                 }

    //                 seen.insert(nums[j]);
    //             }
    //         }

    //         return vector<vector<int>>(unique.begin(), unique.end());
    //     }

public:
    // sort two pointer approach
    // Time: O(n²)
    // Space: O(1)
    vector<vector<int>> threeSum(vector<int> &nums, int target)
    {
        vector<vector<int>> threeSumPairs = {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target)
                {
                    threeSumPairs.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return threeSumPairs;
    }
};

int main()
{
    Solution solution = Solution();
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = solution.threeSum(nums, 0);

    cout << "vector: ";
    for (vector<int> arr : result)
    {
        cout << "<";
        for (int index : arr)
        {
            cout << index << " ";
        }
        cout << ">";
    }
    cout << endl;

    return 0;
}