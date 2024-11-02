/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        // pos_non_zero is the position to put the next non-zero number
        // to ensure the relative order of non-zero numbers
        int pos_non_zero = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[pos_non_zero]);
                ++pos_non_zero;
            }
        }
    }
};
// @lc code=end

