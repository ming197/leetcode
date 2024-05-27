/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // O(m+n) space
        unordered_set<int> rows, cols;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (const auto& row : rows) {
            for (int col = 0; col < matrix[0].size(); ++col) {
                matrix[row][col] = 0;
            }
        }
        for (const auto& col : cols) {
            for (int row = 0; row < matrix.size(); ++row) {
                matrix[row][col] = 0;
            }
        }
    }
};
// @lc code=end

