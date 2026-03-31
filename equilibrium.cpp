#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    bool equilibrium(vector<int>& nums){
        int total = 0;
        int left = 0;

        bool isEquilibrium = false;

        sort(nums.begin(), nums.end());

        for(int i:nums){
            total += i;
        }

        for(int i=0;i<nums.size();i++){
            total -= nums[i];

            if(left==total){
                isEquilibrium = true;
                return isEquilibrium;
            }

            left += nums[i];
        }

        return isEquilibrium;
    }
};

int main(){
    Solution sol;
    vector nums = {8,4, 5, -1, 0, 5};

    bool result = sol.equilibrium(nums);
    cout<<"equilibrium : "<<result<<endl;

    return 0;
}