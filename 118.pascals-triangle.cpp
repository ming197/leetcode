/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        vector<vector<int>> res{{1}};
        // res.push_back({1});
        for (int row = 1; row < numRows; ++row) {
            vector<int> nextRow{1};
            for (int col = 1; col < row; ++col) {
                nextRow.push_back(res[row - 1][col - 1] + res[row - 1][col]);
            }
            nextRow.push_back(1);
            res.push_back(nextRow);
        }
        return res;
    }
};
// @lc code=end

