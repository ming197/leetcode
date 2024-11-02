/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // calculate the water at each index
        // for each index, calculate the left max and right max which is the highest bar on the left and right of the current bar
        vector<int> left(n, 0), right(n, 0);
        left[0] = height[0];
        right[n-1] = height[n-1];
        for (int i = 1; i < n; ++i) {
            left[i] = max(left[i - 1], height[i]);
        }
        for (int i = n - 2; i > -1; --i) {
            right[i] = max(right[i + 1], height[i]);
        }
        int water = 0;
        for (int i = 0; i < n; ++i) {
            water += min(left[i], right[i]) - height[i];
        }
        return water;
    }
};
// @lc code=end

