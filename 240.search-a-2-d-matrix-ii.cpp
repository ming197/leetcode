/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // start from the top right corner
        int row = 0, col = n - 1;
        while (row < m && col > -1)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] < target)
            {
                row++;
            }
            else
            {
                col--;
            }
        }
        return false;
    }
};
// @lc code=end

