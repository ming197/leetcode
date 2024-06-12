/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        vector<int> interval{points[0][0], points[0][1]};
        int ans = 1;
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= interval[1]) {
                // Overlapping intervals
                interval[0] = max(interval[0], points[i][0]);
                interval[1] = min(interval[1], points[i][1]);
            } else {
                interval = {points[i][0], points[i][1]};
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

