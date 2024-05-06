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
        // max index it can jump from i
        vector<int> maxIndex(nums.size(), 0);
        maxIndex[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxIndex[i] = max(maxIndex[i - 1], nums[i - 1] + i - 1);
            if (maxIndex[i] < nums.size() - 1 && maxIndex[i] <= i - 1) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

