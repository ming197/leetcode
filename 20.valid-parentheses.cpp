/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }
        stack<char> stk;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                switch (s[i])
                {
                    case ')':
                        if (stk.empty() || stk.top() != '(') {
                            return false;
                        }
                        break;
                    case ']':
                        if (stk.empty() || stk.top() != '[') {
                            return false;
                        }
                        break;
                    case '}':
                        if (stk.empty() || stk.top() != '{') {
                            return false;
                        }
                        break;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end

