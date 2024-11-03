/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged_intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &interval1, const vector<int> &interval2) {
            if (interval1[0] == interval2[0]) {
                return interval1[1] < interval2[1];
            }
            return interval1[0] < interval2[0];
        });
        int left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            int next_left = intervals[i][0], next_right = intervals[i][1];
            if (next_left > right) {
                merged_intervals.push_back({left, right});
                left = next_left;
                right = next_right;
            } else {
                right = max(right, next_right);
            }
        }
        merged_intervals.push_back({left, right});
        return merged_intervals;
    }
};
// @lc code=end

