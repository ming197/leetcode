/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> delta_x = {0, 0, 1, -1};
    vector<int> delta_y = {1, -1, 0, 0};
    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int new_x = x + delta_x[i];
            int new_y = y + delta_y[i];
            if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size() && grid[new_x][new_y] == '1') {
                dfs(grid, new_x, new_y);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1'){
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

