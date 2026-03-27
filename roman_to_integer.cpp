#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{

public:
    // int romanToInt(string s)
    // {
    //     unordered_map<char, int> roman = {
    //         {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    //     int result = 0;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]])
    //         {
    //             result -= roman[s[i]]; // subtractive case
    //         }
    //         else
    //         {
    //             result += roman[s[i]]; // normal case
    //         }
    //     }

    //     return result;
    // }

    int getValue(char c)
    {
        if (c == 'I')
            return 1;
        if (c == 'V')
            return 5;
        if (c == 'X')
            return 10;
        if (c == 'L')
            return 50;
        if (c == 'C')
            return 100;
        if (c == 'D')
            return 500;
        return 1000;
    }

    int romanToInt(string s)
    {
        int result = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int curr = getValue(s[i]);
            int next = (i + 1 < s.size()) ? getValue(s[i + 1]) : 0;

            if (curr < next)
                result -= curr;
            else
                result += curr;
        }

        return result;
    }
};

int main()
{
    Solution solution = Solution();
    string roman = "MCMXCIV";
    int result = solution.romanToInt(roman);

    cout << "Roman numeral: " << roman << " -> Integer: " << result << endl;

    return 0;
}