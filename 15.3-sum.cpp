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
        for (int i = 0; i < nums.size() - 2; ++i) {
            // 2. skip the duplicate triplet
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int r = nums.size() - 1;
            int target = -nums[i];
            for (int l = i + 1; l < nums.size() - 1; ++l) {
                // 3. skip the duplicate pair
                if (l > i + 1 && nums[l] == nums[l - 1]) {
                    continue;
                }
                // 4. move the right pointer to find the targetable number
                while (l < r && nums[l] + nums[r] > target) {
                    --r;
                }
                // 5. if the left pointer meets the right pointer, break
                if (l == r) {
                    break;
                }
                // 6. if the sum is 0, add the triplet to the result
                if (nums[l] + nums[r] == target) {
                    res.push_back({nums[i], nums[l], nums[r]});
                }
            }
        }
        return res;
    }
};
// @lc code=end

