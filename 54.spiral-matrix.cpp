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
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> passed(m, vector<bool>(n, false));
        int i = 0, j = 0;
        vector<int> res;
        res.emplace_back(matrix[i][j]);
        passed[i][j] = true;
        int count  = m * n;
        // check if the matrix is 1x1
        while (res.size() < count)
        {
            // right
            while (j + 1 < n && !passed[i][j + 1])
            {
                j++;
                res.emplace_back(matrix[i][j]);
                passed[i][j] = true;
                if (res.size() == count)
                    return res;
            }
            // down
            while (i + 1 < m && !passed[i + 1][j])
            {
                i++;
                res.emplace_back(matrix[i][j]);
                passed[i][j] = true;
                if (res.size() == count)
                    return res;
            }
            // left
            while (j - 1 >= 0 && !passed[i][j - 1])
            {
                j--;
                res.emplace_back(matrix[i][j]);
                passed[i][j] = true;
                if (res.size() == count)
                    return res;
            }
            // up
            while (i - 1 >= 0 && !passed[i - 1][j])
            {
                i--;
                res.emplace_back(matrix[i][j]);
                passed[i][j] = true;
                if (res.size() == count)
                    return res;
            }
            
        }
        return res;
    }
};
// @lc code=end

