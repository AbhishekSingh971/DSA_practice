#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;

class Solution
{
    // Approach	Time	    Space	 Practical      ?
    // Two pointers	        O(n³)	    O(1)    ✅ Best choice
    // Hash map           	O(n²)   	O(n²)	⚠️ Rarely used
    // Brute force	        O(n⁴)	    O(1)	❌ Too slow
// public:
    // Time: O(n²)
    // Space: O(n²)
    // hash map
    // vector<vector<int>> fourSum(vector<int> &nums, int target)
    // {
    //     int n = nums.size();
    //     set<vector<int>> st;

    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i + 1; j < n; j++)
    //         {
    //             unordered_set<long long> seen;

    //             for (int k = j + 1; k < n; k++)
    //             {
    //                 long long sum = (long long)nums[i] + nums[j] + nums[k];
    //                 long long fourth = target - sum;

    //                 // check if needed value already seen
    //                 if (seen.count(fourth))
    //                 {
    //                     vector<int> quad = {nums[i], nums[j], nums[k], (int)fourth};
    //                     sort(quad.begin(), quad.end());
    //                     st.insert(quad);
    //                 }

    //                 seen.insert(nums[k]);
    //             }
    //         }
    //     }

    //     return vector<vector<int>>(st.begin(), st.end());
    // }

public:
    // Time: O(n³)
    // Space: O(1)
    // sort and 2 pointer
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> fourSumPairs = {};
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i <= n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j <= n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1;
                int right = n - 1;
                while (left < right)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target)
                    {
                        fourSumPairs.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right && nums[right] == nums[right - 1])
                            right++;

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
        }

        return fourSumPairs;
    }
};

int main()
{
    Solution sol;
    vector<int> num = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> results = sol.fourSum(num, 0);

    cout << "fourSum : ";
    for (vector<int> array : results)
    {
        cout << "<";
        for (int i : array)
        {
            cout << i;
        }
        cout << "> ";
    }

    return 0;
}