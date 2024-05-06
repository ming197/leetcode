/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        // two pointers
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
// @lc code=end

