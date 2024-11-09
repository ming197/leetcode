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

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtrack(candidates, target, 0, 0, temp);
        return result;
    }

    void backtrack(vector<int> &candidates, int target, int start, int sum, vector<int> &temp) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            // if the sum is greater than the target, break
            if (sum + candidates[i] > target) break;
            temp.push_back(candidates[i]);
            backtrack(candidates, target, i, sum + candidates[i], temp);
            temp.pop_back();
        }
    }
};
// @lc code=end

