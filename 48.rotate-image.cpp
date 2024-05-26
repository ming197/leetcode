/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // swap the matrix[i][j] and matrix[j][i]
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= i; ++j) {
                swap(matrix, i, j, j, i);
            }
        }
        // swap the matrix[i][j] and matrix[i][n-j-1]
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                swap(matrix, i, j, i, n - j - 1);
            }
        }
    }

    void swap(vector<vector<int>> &matrix, int i, int j, int m, int n) {
        int temp = matrix[i][j];
        matrix[i][j] = matrix[m][n];
        matrix[m][n] = temp;
    }
};
// @lc code=end

