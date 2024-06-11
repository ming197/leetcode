/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int k = 0;
        // add all the intervals that come before the new interval
        while (k < n && intervals[k][1] < newInterval[0]) {
            ans.push_back(intervals[k++]);
        }
        // merge all the intervals that overlap with the new interval
        while (k < n && intervals[k][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[k][0]);
            newInterval[1] = max(newInterval[1], intervals[k][1]);
            k++;
        }
        // add the merged interval
        ans.push_back(newInterval);
        // add all the intervals that come after the new interval
        while (k < n) {
            ans.push_back(intervals[k++]);
        }
        return ans;
    }
};
// @lc code=end

