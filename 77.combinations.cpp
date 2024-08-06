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
        // get the combination of k elements from start to n
        // the first element is start, the last element is n - k + 1, which is the last k element
        // ensure the number of elements is enough
        for (int i = start; i <= n - k + 1; ++i) {
            tmp_combation.push_back(i);
            DFS(n, k - 1, i + 1);
            tmp_combation.pop_back();
        }
    }
};
// @lc code=end

