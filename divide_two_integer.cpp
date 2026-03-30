#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        int value = dividend/divisor;
        return value;
    }
};

int main() {
    Solution sol;
    int dividend = -2147483648;
    int divisor = -1;
    int result = sol.divide(dividend, divisor);
    cout << "Result: " << result << endl;
    return 0;
}