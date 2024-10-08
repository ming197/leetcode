/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // dp[i][j] means the minimum number of operations to convert word1[0..i) to word2[0..j)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // base case, initialize the first row and the first column
        // dp[i][0] means the minimum number of operations to convert word1[0..i) to an empty string
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = i;
        }
        // dp[0][j] means the minimum number of operations to convert an empty string to word2[0..j)
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
        // dp[][j] must be inferred from dp[][j-1]
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
            for (int i = 1; i <= m; ++i) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
                    // dp[i - 1][j - 1] means replace operation
                    // dp[i - 1][j] means delete operation
                    // dp[i][j - 1] means insert operation
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    string word1 = "hros";
    string word2 = "ros";
    Solution sol;
    cout << sol.minDistance(word1, word2) << endl;
}
// @lc code=end

