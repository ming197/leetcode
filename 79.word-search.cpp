/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (BFS(board, i, j, word)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool BFS(vector<vector<char>>& board, int i, int j, string word) {
        int m = board.size();
        int n = board[0].size();
        // check if the first character is the same
        if (board[i][j] != word[0]) {
            return false;
        }
        if (word.size() == 1) {
            return true;
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({i, j});
        int depth = 0;
        // only push the character that is equal to the next character
        while (!q.empty())
        {
            int size = q.size();
            ++depth;
            for (int j = 0; j < size; ++j) {
                auto [x, y] = q.front();
                visited[x][y] = true;
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int next_x = x + dx[i];
                    int next_y = y + dy[i];
                    // in the board && not visited && equal to the next character
                    if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visited[next_x][next_y]|| board[next_x][next_y] != word[depth]) {
                        continue;
                    }
                    if (depth == word.size() - 1) {
                        return true;
                    }
                    q.push({next_x, next_y});
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        function<bool(int, int, int)> backtrack = [&](int i, int j, int k) {
            if (k == word.length()) {
                return true;
            }
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
                return false;
            }
            
            char temp = board[i][j];
            board[i][j] = '\0';
            
            if (backtrack(i + 1, j, k + 1) || backtrack(i - 1, j, k + 1) || 
                backtrack(i, j + 1, k + 1) || backtrack(i, j - 1, k + 1)) {
                return true;
            }
            
            board[i][j] = temp; 
            return false;
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

