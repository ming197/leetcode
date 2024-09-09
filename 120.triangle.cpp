/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // we can use the original triangle to store the dp values
        // or use a one dimensional vector to store the dp values
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0][0] = triangle[0][0];
        int res = (n == 1 ? dp[0][0] : INT_MAX);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);
                dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + triangle[i][j + 1]);
                if (i == n - 1)
                {
                    res = min(res, min(dp[i][j], dp[i][j + 1]));
                }
            }
        }
        return res;
    }
};
// @lc code=end

