/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = m ? obstacleGrid[0].size() : 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (obstacleGrid[0][0] == 0) dp[0][0] = 1;
        if (obstacleGrid[m-1][n-1] == 1) return 0;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0) dp[i][0] = dp[i-1][0];
        }
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[0][j] == 0) dp[0][j] = dp[0][j - 1];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

