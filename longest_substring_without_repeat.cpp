#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     unordered_map<char, int> map;
    //     int left = 0, max_length = 0;

    //     for(int right =0; right<s.size(); right++){
    //         if(map.find(s[right]) != map.end()){
    //             left = max(left, map[s[right]] + 1);
    //         }

    //         map[s[right]] = right;
    //         max_length = max(max_length, right-left+1);
    //     }

    //     return max_length;
    // }

    // better approch
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        vector<int> lastSeen(256,-1);
        int left = 0, max_length = 0;

        for(int right =0; right<s.size(); right++){
            if(lastSeen[s[right]]>=left){
                left = lastSeen[s[right]] + 1;
            }

            lastSeen[s[right]] = right;
            max_length = max(max_length, right-left+1);
        }

        return max_length;
    }
};

int main(){
    Solution solution = Solution();

    int result = solution.lengthOfLongestSubstring("abcabcbb");
    cout<<result;
    
    return 0;
}