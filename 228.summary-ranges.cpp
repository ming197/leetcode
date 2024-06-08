/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        // two pointers, [l, r)
        int l = 0, r = 0;
        while (r < n)
        {
            // find the range [l, r)
            while (l == r || r < n && nums[r] == nums[r - 1] + 1)
            {
                ++r;
            }
            // add the range to the result
            if (l == r - 1)
            {
                result.push_back(to_string(nums[l]));
            }
            else
            {
                result.push_back(to_string(nums[l]) + "->" + to_string(nums[r - 1]));
            }
            // update the left pointer
            l = r;
        }
        return result;
    }
};
// @lc code=end

