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
        // 1. the water height is decided by the left and right boundary
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);
        // 2. the left boundary is the highest left height
        maxLeft[0] = height[0];
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        // 3. the right boundary is the highedt right
        maxRight[n - 1] = height[n - 1];
        for (int i = n - 2; i > -1; --i) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }
        // 3. and the rain water is min(maxLeft[i], maxRight[i]) - height[i]
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return res;
    }
};
// @lc code=end

