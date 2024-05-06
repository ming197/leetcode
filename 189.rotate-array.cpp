/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        revert(nums, 0, nums.size() - 1);
        revert(nums, 0, k - 1);
        revert(nums, k, nums.size() - 1);
    }

    void revert(vector<int>& nums, int first, int last) {
        while (first < last)
        {
            swap(nums[first], nums[last]);
            ++first;
            --last;
        }
    }
};
// @lc code=end

