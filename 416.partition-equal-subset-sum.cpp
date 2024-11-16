/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1) return false;
        int target = sum / 2;
        vector<vector<bool>> f(n, vector<bool>(target + 1, false));
        // initialize
        if (nums[0] < target) f[0][nums[0]] = true;
        for (int i = 0; i < n; ++i)
        {
            f[i][0] = true;
        }
        for (int i = 1; i < n; ++i)
        {
            // f[i][j] = f[i - 1][j] || f[i - 1][j - nums[i]]
            for (int j = 1; j <= target; ++j)
            {
                if (j >= nums[i])
                {
                    f[i][j] = f[i - 1][j] || f[i - 1][j - nums[i]];
                }
                else
                {
                    f[i][j] = f[i - 1][j];
                }
            }
        }
        return f[n - 1][target];
    }
};
// @lc code=end

