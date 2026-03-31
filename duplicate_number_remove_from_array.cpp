#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    int arraySize(vector<int>& nums){
       int left = 0;
       for (int j = 1; j < nums.size(); j++)
       {    
            if(nums[left] != nums[j]){
                left+=1;
                nums[left] = nums[j];
            }; 
       }
       return left+1;
    }
};

int main(){
    Solution sol;
    vector nums = {0,0,1,1,2,2,3,3,4,4,5,5,5};

    int result = sol.arraySize(nums);
    cout<<"arraySize : "<<result<<endl;
    for (int i = 0; i < result; i++)
    {
        cout<< nums[i]<<endl;
    }
    

    return 0;
}