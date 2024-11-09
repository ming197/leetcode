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
    vector<string> generateParenthesis(int n) {
        string temp_str("");
        backtrack(n, 0, 0, temp_str);
        return result;
    }

    void backtrack(int n, int left, int right, string &temp_str)
    {
        if (temp_str.size() == 2 * n)
        {
            result.push_back(temp_str);
            return;
        }
        if (left < n)
        {
            temp_str.push_back('(');
            backtrack(n, left + 1, right, temp_str);
            temp_str.pop_back();
        }
        if (right < left)
        {
            temp_str.push_back(')');
            backtrack(n, left, right + 1, temp_str);
            temp_str.pop_back();
        }
    }
};
// @lc code=end

