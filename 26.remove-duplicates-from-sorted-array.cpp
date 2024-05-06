/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> non_duplicate_nums;
        int k = 1;
        int len = nums.size();
        for (int i = 1; i < len; ++i) {
            // nums is non-decreasing, no need to use the "set"
            if (nums[i] != nums[k - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
// @lc code=end

