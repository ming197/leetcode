/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        unordered_set<int> visited;
        // n >= 2
        int n = board.size();
        queue<int> q;
        q.push(1);
        visited.insert(1);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            // iterate the nodes in the same level
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();
                // iterate the next 6 nodes
                for (int delta = 1; delta <= 6; ++delta) {
                    int next = curr + delta;
                    if (next > n * n) {
                        break;
                    }
                    // get the position of the next node
                    int x = n - 1 - (next - 1) / n;
                    int y = (n - 1 - x) % 2 == 0 ? (next - 1) % n : n - 1 - (next - 1) % n;
                    if (board[x][y] != -1) {
                        next = board[x][y];
                    }
                    if (visited.count(next)) {
                        continue;
                    }
                    // find the destination
                    if (next == n * n) {
                        return step + 1;
                    }
                    visited.insert(next);
                    q.push(next);
                }
            }
            ++step;
        }
        return -1;
    }
};
// @lc code=end

