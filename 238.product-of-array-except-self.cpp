/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums);
        // prefix product
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] *= nums[i - 1];
        }
        // suffix product
        for (int i = res.size() - 2; i > -1; --i) {
            res[i] *= res[i + 1];
        }
        res[0] = res[1];
        for (int i = 1; i < res.size() - 1; ++i) {
            res[i] = nums[i - 1] * res[i + 1];
        }
        res[res.size() - 1] = nums[res.size() - 2];
        return res;
    }
};
// @lc code=end

