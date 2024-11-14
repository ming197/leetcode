/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        // dp[i] = the least number of perfect square numbers which sum to i
        // dp[i] = min(dp[i - j * j] + 1), 1 <= j * j <= i
        // dp[0] = 0, which is used to 
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int min_num = INT_MAX;
            // dp_(i - delta), delta = j * j
            // find the min_num
            // cannot use the binary search here, because the dp[i] is not sorted
            for (int j = 1; j * j <= i; ++j)
            {
                min_num = min(min_num, dp[i - j * j]);
            }
            dp[i] = min_num + 1;
        }
        return dp[n];
    }
};
// @lc code=end

