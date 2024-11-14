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
        // f[i] = f[j] && dict.find(s.substr(j, i - j)) != dict.end()
        // it means that s[0, j) is breakable and s[j, i) is in the dict]
        vector<bool> f(n + 1, false);
        f[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (f[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[s.size()];
    }
};
// @lc code=end

