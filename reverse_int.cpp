#include <iostream>
using namespace std;

class Solution {
public:
    //both solutions are same time and space complexity, just different way to check overflow
    // int reverse(int x) {
    //     int reverseNum = 0;

    //     while(x != 0){
    //       int digit = x % 10;

    //         // Overflow check
    //         if (reverseNum > INT_MAX / 10 || 
    //            (reverseNum == INT_MAX / 10 && digit > 7))
    //             return 0;

    //         if (reverseNum < INT_MIN / 10 || 
    //            (reverseNum == INT_MIN / 10 && digit < -8))
    //             return 0;

    //         reverseNum = reverseNum * 10 + digit;
    //         x /= 10;
    //     }
    //     return reverseNum;
    // }

    int reverse(int x) {
        int ans = 0;

        while (x) {
            int d = x % 10;

            if (ans > INT_MAX/10 || ans < INT_MIN/10)
                return 0;

            ans = ans * 10 + d;
            x /= 10;
        }
        return ans;
    }
};



int main(){
    Solution solution = Solution();
    int integer;
    cin>>integer;
    int result = solution.reverse(integer);
    cout<<"result :"<<result<<endl;

    return 0;
}