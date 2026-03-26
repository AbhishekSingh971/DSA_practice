#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> indices;
    //     int number;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         for(int j=0;j<nums.size(); j++){
    //             if(i!=j){
    //                 if(nums[i] + nums[j] == target){
    //                     indices.push_back(i);
    //                     indices.push_back(j);
    //                     cout<<nums[i]<<"+"<<nums[j]<<endl;
    //                     return indices;
    //                 }
    //             }
    //         }
    //     }
    //     return indices;
    // }

public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }
        // Return an empty vector if no solution is found
        return {};
    }
};


int main(){
    Solution solution = Solution();
    vector<int> nums = {2, 7, 11, 15};

    vector<int> result = solution.twoSum(nums, 17);

    cout << "Indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}