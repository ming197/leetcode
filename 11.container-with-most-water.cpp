/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l < r)
        {
            // move the lower line
            // otherwise, the container cannot be larger than now
            if (height[l] < height[r]) {
                res = max(res, height[l] * (r - l));
                ++l;
            } else {
                res = max(res, height[r] * (r - l));
                --r;
            }
        }
        return res;
    }
};
// @lc code=end

