/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    // x is the index of the current element
    // the elements before x are fixed
    void dfs(vector<int> nums, int x) {
        if (x == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = x; i < nums.size(); i++) {
            swap(nums[i], nums[x]);
            dfs(nums, x + 1);   
            swap(nums[i], nums[x]);
        }
    }
};
// @lc code=end

