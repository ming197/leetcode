/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        int s_pos = 0, t_pos = 0;
        while (s_pos < n && t_pos < m)
        {
            if (s[s_pos] == t[t_pos]) {
                ++s_pos;
            }
            ++t_pos;
        }
        return s_pos == n;
    }
};
// @lc code=end

