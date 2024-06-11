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
        // sort the intervals based on the start time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& interval1, const vector<int> interval2){
            if (interval1[0] != interval2[0]) return interval1[0] < interval2[0];
            return interval1[1] < interval2[1];
        });
        vector<vector<int>> merged;
        int l = intervals[0][0], r = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            int left = intervals[i][0], right = intervals[i][1];
            if (left <= r) {
                r = max(r, right);
            } else {
                merged.push_back({l, r});
                l = left;
                r = right;
            }
        }
        merged.push_back({l, r});
        return merged;
    }
};
// @lc code=end

