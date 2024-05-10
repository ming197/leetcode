/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int sub_len = strs[0].size();
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < sub_len; ++j) {
                if(strs[0][j] != strs[i][j]) {
                    sub_len = j;
                }
            }
        }
        return strs[0].substr(0, sub_len);
    }
};
// @lc code=end

