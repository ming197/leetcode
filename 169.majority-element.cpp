/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int val = nums[0];
        int cnt = 1;
        for (int i = 1; i < len; ++i) {
            if (cnt == 0) {
                val = nums[i];
                // assign the value and count + 1
                ++cnt;
            } else if (nums[i] == val) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return val;
    }
};
// @lc code=end

