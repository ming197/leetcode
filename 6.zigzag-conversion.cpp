/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vec_str(numRows, "");
        int row = 0;
        int pos = 0;
        while (pos < s.size()) {
            // downwards
            row = 0; // row may < 0 after the last iteration
            while (row < numRows && pos < s.size()) {
                vec_str[row++] += s[pos++];
            }
            // diagonally upwards
            row = numRows - 2;
            while (row > 0 && pos < s.size())
            {
                vec_str[row--] += s[pos++];
            }
        }
        string res;
        for (int i = 0; i < numRows; ++i) {
            res += vec_str[i];
        }
        return res;
    }
};
// @lc code=end

