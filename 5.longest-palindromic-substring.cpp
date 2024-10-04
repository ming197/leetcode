/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int max_len = 1;
        int start = 0;
        int end = 0;
        std::vector<std::vector<bool>> dp(s.length(), std::vector<bool>(s.length(), false));
        
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;
            for (int j = 0; j < i; ++j) {
                // ensure dp[j + 1][i - 1] is calculated before dp[j][i]
                // j + 1 <= i - 1, 
                // any dp[x][y] in the last loop is calculated, so dp[j + 1][i - 1] is calculated
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                    if (i - j + 1 > max_len) {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("aaaa") << endl;
    // cout << sol.longestPalindrome("cbbd") << endl;
    return 0;
} 
// @lc code=end