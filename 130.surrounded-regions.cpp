/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> delta_x = {0, 0, 1, -1};
    vector<int> delta_y = {1, -1, 0, 0};
    bool is_edge(int x, int y, vector<vector<char>>& grid) {
        return x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1;
    }
    bool is_valid(int x, int y, vector<vector<char>>& grid) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }
    bool is_surrounded = false;
    void dfs(vector<vector<char>>& grid, int x, int y, bool& is_surrounded) {
        if (grid[x][y] != 'O') {
            return;
        }
        // set the cell to 'Y' to avoid revisiting
        grid[x][y] = 'Y';
        // if the cell is on the edge, it is not surrounded
        if (is_edge(x, y, grid)) {
            is_surrounded = false;
        }
        for (int i = 0; i < 4; i++) {
            int new_x = x + delta_x[i];
            int new_y = y + delta_y[i];
            if (is_valid(new_x, new_y, grid) && grid[new_x][new_y] == 'O') {
                dfs(grid, new_x, new_y, is_surrounded);   
            }
        }
    }
    void make_surrounded(vector<vector<char>>& grid, int x, int y) {
        if (grid[x][y] != 'Y') {
            return;
        }
        grid[x][y] = 'X';
        for (int i = 0; i < 4; i++) {
            int new_x = x + delta_x[i];
            int new_y = y + delta_y[i];
            if (is_valid(new_x, new_y, grid) && grid[new_x][new_y] == 'Y') {
                make_surrounded(grid, new_x, new_y);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') {
                    // to judge whether it is an area surrounded by 'X'
                    is_surrounded = true;
                    dfs(board, i, j, is_surrounded);
                    // if the area is surrounded, make it 'X'
                    if (is_surrounded) {
                        make_surrounded(board, i, j);
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                // if the cell is 'Y', make it 'O'
                if (board[i][j] == 'Y') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    // vector<vector<char>> board = {{'X', 'X', 'X'}, {'X', 'O', 'X'}, {'X', 'X', 'X'}};
    sol.solve(board);
}
// @lc code=end

