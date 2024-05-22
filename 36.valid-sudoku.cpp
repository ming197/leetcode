/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // use 3 sets to store the digits in each row, column and box
        vector<unordered_set<char>> rowSet(9), colSet(9), boxSet(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;  
                }
                char digit = board[i][j];
                if (rowSet[i].count(digit) || colSet[j].count(digit) || boxSet[i / 3 * 3 + j / 3].count(digit)) {
                    return false;
                }
                rowSet[i].insert(digit);
                colSet[j].insert(digit);
                boxSet[i / 3 * 3 + j / 3].insert(digit);
            }  
        }
        return true;
    }
};
// @lc code=end

