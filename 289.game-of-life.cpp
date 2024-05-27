/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        // count the number of live cells around the cell
        auto count = [&] (int row, int col) -> int
        {
            vector<int> x = {0, 0, 1, 1, 1, -1, -1, -1};
            vector<int> y = {1, -1, 0, 1, -1, 0, 1, -1};
            int live_cells = 0;
            for (int i = 0; i < 8; i++)
            {
                int new_row = row + x[i];
                int new_col = col + y[i];
                if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n)
                {
                    // use & 1 to get the current state of the cell
                    live_cells += board[new_row][new_col] & 1;
                }
            }
            return live_cells;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live_cells = count(i, j);
                // if the cell is alive
                if (board[i][j] & 1 == 1) {
                    if (live_cells < 2 || live_cells > 3) { // if the cell will die in the next state
                        board[i][j] = 1;
                    } else { // the cell will live in the next state
                        board[i][j] = 3;
                    }
                } else { // if the cell is dead
                    if (live_cells == 3) {
                        // reproduction in the next state
                        board[i][j] = 2;
                    }
                }
            }
        }
        // right shift by 1 to get the next state
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; j++)
            {
                board[i][j] >>= 1;
            }
        }
    }
};
// @lc code=end

