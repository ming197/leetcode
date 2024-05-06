/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        // min step to i from 0
        vector<int> minSteps(len, 10010);
        minSteps[0] = 0;
        for (int i = 0; i < len; ++i) {
            int maxIndex = min(i + nums[i] + 1, len); 
            for (int j = i + 1; j < maxIndex; ++j) {
                minSteps[j] = min(minSteps[i] + 1, minSteps[j]);
                if (j == len - 1) {
                    return minSteps[j];
                }
            }
        }
        return minSteps[len - 1];
    }
};
// @lc code=end

