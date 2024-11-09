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
        deque<char> stk;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stk.push_front(ch);
            } else {
                if (stk.empty()) {
                    return false;
                }
                if (ch == ')' && stk.front() != '(') {
                    return false;
                }
                if (ch == ']' && stk.front() != '[') {
                    return false;
                }
                if (ch == '}' && stk.front() != '{') {
                    return false;
                }
                stk.pop_front();
            }
        }
        return stk.empty();
    }
};
// @lc code=end

