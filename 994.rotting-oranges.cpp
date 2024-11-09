/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> delta_x = {0, 0, 1, -1};
    vector<int> delta_y = {1, -1, 0, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int new_cnt = 0;
        // use deque to implement BFS
        deque<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // push all rotten oranges into the queue
                if (grid[i][j] == 2) {
                    q.push_back({i, j});
                }
                // count the number of fresh oranges
                if (grid[i][j] == 1) {
                    new_cnt++;
                }
            }
        }
        // edge case: if there is no fresh orange
        if (new_cnt == 0) {
            return 0;
        }
        int res = 0;
        while (!q.empty()) {
            ++res;
            int size  = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop_front();
                for (int j = 0; j < 4; ++j) {
                    int new_x = x + delta_x[j];
                    int new_y = y + delta_y[j];
                    if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y] == 1) {
                        grid[new_x][new_y] = 2;
                        q.push_back({new_x, new_y});
                        new_cnt--;
                        if (new_cnt == 0) {
                            return res;
                        }
                    }
                }
            }
        }
        return new_cnt == 0 ? res : -1;
    }
};
// @lc code=end

