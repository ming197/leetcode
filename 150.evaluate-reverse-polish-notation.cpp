/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for (const auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int y = stoi(stk.top());
                stk.pop();
                int x = stoi(stk.top());
                stk.pop();
                if (token == "+") {
                    stk.push(to_string(x + y));
                } else if (token == "-") {
                    stk.push(to_string(x - y));
                } else if (token == "*") {
                    stk.push(to_string(x * y));
                } else {
                    stk.push(to_string(x / y));
                }
            } else {
                stk.push(token);
            }
        }
        return stoi(stk.top());
    }
};
// @lc code=end

