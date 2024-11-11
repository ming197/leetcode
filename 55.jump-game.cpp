/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_reachable = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > max_reachable)
            {
                return false;
            }
            max_reachable = max(max_reachable, i + nums[i]);
            if (max_reachable >= n - 1)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

