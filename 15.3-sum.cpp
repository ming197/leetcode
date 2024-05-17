/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // two pointers
        // sort first
        sort(nums.begin(), nums.end());
        // 1. fix the first number
        for (int i = 0; i < nums.size(); ++i) {
            // 2. skip the duplicate triplet
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
               if (nums[i] + nums[l] + nums[r] == 0) {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    ++l;
                    // 2. skip the duplicate triplet
                    while (l < r && nums[l] == nums[l - 1]) {
                        ++l;
                    }
               } else if (nums[i] + nums[l] + nums[r] > 0) {
                    --r;
                    // 2. skip the duplicate triplet
                    while (l < r && nums[r] == nums[r + 1]) {
                        --r;
                    }
               } else {
                    ++l;
                    // 2. skip the duplicate triplet
                    while (l < r && nums[l] == nums[l - 1]) {
                        ++l;
                    }
               }
            }
        }
        return res;
    }
};
// @lc code=end

