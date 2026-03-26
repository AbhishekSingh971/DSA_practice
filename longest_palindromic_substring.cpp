#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      if(s.size()<=1) return s;
        int start = 0, max_length = 0;

        for(int i=0; i<s.size(); i++){
            expand(s, i , i, start, max_length);
            expand(s,i, i+1, start, max_length);
        }
        return s.substr(start, max_length);
    }

private:
    void expand(string& s, int left, int right, int& start,int& max_length){
        while(left >= 0 && right < s.length() && s[left]==s[right]){
            int current = right-left+1;
            if(current>max_length){
                start = left;
            max_length = max(current, max_length);
            }
            left--;
            right++;
        }
    }
};

int main(){
    Solution solution = Solution();
    string result = solution.longestPalindrome("abbaba");

    cout<<"longest palindromic substring"<<result<<endl;

    return 0;
}