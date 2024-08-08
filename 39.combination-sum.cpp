/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    int sum = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        DFS(candidates, target);
        return result;
    }

    void DFS(vector<int>& candidates, int target, int start = 0) {
        if (sum == target) {
            result.push_back(tmp);
            return;
        }
        // cannot be duplicated, so start from i
        // and one element can be used multiple times
        for (int i = start; i < candidates.size(); i++) {
            if (sum + candidates[i] > target) {
                return;
            }
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            DFS(candidates, target, i);
            sum -= candidates[i];
            tmp.pop_back();
        }
    }
};
// @lc code=end

