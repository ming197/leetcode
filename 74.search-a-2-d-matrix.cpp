/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int left_row = 0, right_row = m - 1;
        while (left_row <= right_row) {
            // binary search for row
            int mid_row = left_row + (right_row - left_row) / 2;
            if (matrix[mid_row][0] <= target && target <= matrix[mid_row][n - 1]) {
                // binary search for column
                int left_col = 0, right_col = n - 1;
                while (left_col <= right_col) {
                    int mid_col = left_col + (right_col - left_col) / 2;
                    if (matrix[mid_row][mid_col] == target) {
                        return true;
                    } else if (matrix[mid_row][mid_col] < target) {
                        left_col = mid_col + 1;
                    } else {
                        right_col = mid_col - 1;
                    }
                }
                return false;
            } else if (matrix[mid_row][0] < target) {
                left_row = mid_row + 1;
            } else {
                right_row = mid_row - 1;
            }
        }
        return false;
    }
};
// @lc code=end

