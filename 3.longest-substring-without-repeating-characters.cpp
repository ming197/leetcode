/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        // substr: [l, r)
        int l = 0, r = 0, res = 0;
        while (l <= r && r < n)
        {
            if (mp.find(s[r]) == mp.end() || mp[s[r]] == 0)
            {
                ++mp[s[r++]];
                res = max(res, r - l);
            } else {
                --mp[s[l]];
                ++l;
            }
        }
        return res;
    }
};
// @lc code=end

