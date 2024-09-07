/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n, false);
        for (int i = 0; i < n; ++i) {
            // judge substring [0, i] of s can be segmented
            for (int prefix_len = 0; prefix_len < i + 1 && !dp[i]; ++prefix_len) {
                if (prefix_len == 0) {
                    dp[i] = dict.count(s.substr(0, i + 1));
                } else {
                    dp[i] = dp[prefix_len - 1] && dict.count(s.substr(prefix_len, i - prefix_len + 1));
                }
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

