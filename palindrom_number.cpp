#include <iostream>
using namespace std;

class Solution {
public:
//this approch taking too much space so we need to use the long long palindrome with big space complaxity 
    // bool isPalindrome(int x) {
    //    if (x < 0) return false;

    //     int num = x;
    //     int palindrome = 0;

    //     while (num != 0) {
    //         int reminder = num % 10;
    //         num = num / 10;
    //         palindrome = palindrome * 10 + reminder;
    //     }

    //     return palindrome == x;
    // }

    //this only itrate half times;
    bool isPalindrome(int x){
        if(x<0 || (x%10 == 0 && x != 0)) return false;

        int halfreverse = 0;

        while(x > halfreverse){
            halfreverse = halfreverse *10 + x%10;
            x/=10;
        }

        return (x == halfreverse || x == halfreverse/10);
    }
};

int main(){
    Solution solution = Solution();
    int integer;
    cin>>integer;
    bool result = solution.isPalindrome(integer);
    cout<<"result :"<<result<<endl;

    return 0;
}