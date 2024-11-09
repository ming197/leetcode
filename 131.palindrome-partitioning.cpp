/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<string>> result;
    vector<vector<bool>> dp;
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp = vector<vector<bool>>(n, vector<bool>(n, false));
        // dp[i][j] = true if s[i:j] is a palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            if (i < n - 1) dp[i][i + 1] = (s[i] == s[i + 1]);
        }
        for (int len = 3; len <= n; ++len)
        {
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
        vector<string> temp;
        backtrack(s, 0, temp);
        return result;
    }

    void backtrack(string &s, int start, vector<string> &temp) {
        if (start == s.size()) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (dp[start][i]) {
                temp.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, temp);
                temp.pop_back();
            }
        }
    }
};
// @lc code=end

