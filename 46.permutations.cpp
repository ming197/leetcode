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
    unordered_set<int> visited;
    vector<vector<int>> result;
    vector<int> tmp;
    vector<vector<int>> permute(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        DFS(nums);
        return result;
    }
    void DFS(vector<int> &nums) {
        if (tmp.size() == nums.size()) {
            result.push_back(tmp);
            return;
        }
        for (int x : nums) {
            if (visited.find(x) != visited.end()) {
                continue;
            }
            visited.insert(x);
            tmp.push_back(x);
            DFS(nums);
            tmp.pop_back();
            visited.erase(x);
        }
    }
};
// @lc code=end

