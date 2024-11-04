/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> delta_row{0, 1, 0, -1};
        vector<int> delta_col{1, 0, -1, 0};
        int m = matrix.size();
        int n = matrix[0].size();
        // we can update the element in the matrix to an invalid value to avoid using extra space
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        int step = 0;
        int row = 0, col = 0;
        int direction = 0;
        vector<int> res;
        while (step++ < m * n) {
            // update result and flag
            res.emplace_back(matrix[row][col]);
            flag[row][col] = true;
            // find the next valid step 
            int next_row = row + delta_row[direction];
            int next_col = col + delta_col[direction];
            if (next_row < 0 || next_row > m - 1 || next_col < 0 || next_col > n - 1 || flag[next_row][next_col]) {
                direction = (direction + 1) % 4;
            }
            row += delta_row[direction];
            col += delta_col[direction];
        }
        return res;
    }
};
// @lc code=end

