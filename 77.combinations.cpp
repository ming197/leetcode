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
        if (tmp_combation.size() == k) {
            result.push_back(tmp_combation);
            return;
        }
        // pruning, if the number of elements in tmp_combation and the number of elements from start to n is less than k, return
        if (tmp_combation.size() + n - start + 1 < k) {
            return;
        }
        // get the combination of k elements from start to n
        for (int i = start; i <= n; ++i) {
            tmp_combation.push_back(i);
            DFS(n, k, i + 1);
            tmp_combation.pop_back();
        }
    }
};
// @lc code=end

