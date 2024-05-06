/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return int(nums.size());
        }
        int k = 2;
        int len = nums.size();

        for (int i = 2; i < len; ++i) {
            if (nums[i] != nums[k - 1]) {
                nums[k++] = nums[i];
            } else if (nums[i] != nums[k - 2]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
// @lc code=end

