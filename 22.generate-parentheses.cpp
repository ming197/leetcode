/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<string> result;
    string tmp;
    vector<string> generateParenthesis(int n) {
        DFS(n, 0, 0);
        return result;
    }
    void DFS(int n, int left, int right) {
        if (left == n && right == n) {
            result.push_back(tmp);
            return;
        }
        // Recursive branch
        if (left == right) {
            tmp.push_back('(');
            DFS(n, left + 1, right);
            tmp.pop_back();
        } else if (left > right) {
            // step1: add '('
            if (left < n) {
                tmp.push_back('(');
                DFS(n, left + 1, right);
                tmp.pop_back();
            }
            // step2: add ')'
            tmp.push_back(')');
            DFS(n, left, right + 1);
            tmp.pop_back();
        }

    }
};
// @lc code=end

