/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back({});
        // the size of the subset
        for (int i = 1; i <= nums.size(); i++) {
            vector<int> temp;
            backtrack(nums, 0, i, temp);
        }
        return result;
    }

    void backtrack(vector<int>& nums, int start, int k, vector<int>& temp) {
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }
        // start from the current index
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            backtrack(nums, i + 1, k, temp);
            temp.pop_back();
        }
    }
};
// @lc code=end

