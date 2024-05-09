/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums(4, 0);
        int i = 0;
        while (num > 0)
        {
            nums[i++] = num % 10;
            num /= 10;
        }
        string res;
        // Thousands
        res += digitToString(nums[3], "s", "s", "M");
        // hundreds
        res += digitToString(nums[2], "M", "D", "C");
        // tenth
        res += digitToString(nums[1], "C", "L", "X");
        // ones digit
        res += digitToString(nums[0], "X", "V", "I");
        return res;
    }

    string digitToString(int x, string s1, string s2, string s3) {
        string res;
        if (x == 9) {
            res = s3 + s1;
        } else if (x == 4) {
            res = s3 + s2;
        } else if (x < 4) { // x = 0, 1, 2, 3
            res = string(x, s3[0]);
        } else { // x = 5, 6, 7, 8
            res = s2 + string(x - 5, s3[0]);
        }
        return res;
    }
};
// @lc code=end

