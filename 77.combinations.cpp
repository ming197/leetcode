/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp_combation;
    vector<vector<int>> combine(int n, int k) {
        DFS(n, k, 1);
        return result;
    }
    void DFS(int n, int k, int start) {
        if (k == 0) {
            result.push_back(tmp_combation);
            return;
        }
        // i represents the first element of the combination
        // the largest of the first element is n - k + 1, which ensures that the combination has k elements
        for (int i = start; i <= n - k + 1; ++i) {
            tmp_combation.push_back(i);
            // the next element of the combination belongs to the range [i + 1, n - (k - 1) + 1]
            // which ensure there is no duplicate combination and prune the search space
            DFS(n, k - 1, i + 1);
            tmp_combation.pop_back();
        }
    }
};
// @lc code=end

