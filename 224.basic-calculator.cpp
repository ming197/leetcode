/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sum = 0;
        int sign = 1;
        stack<int> stk;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                sum = s[i] -'0';
                while (i + 1 < n && isdigit(s[i + 1]))
                {
                    sum = sum * 10 + (s[i + 1] -'0');
                    i++;
                }
                result += sum*sign;
            }
            
            else if (s[i] == '+')
            {
                sign = 1;
            }
            else if (s[i] == '-')
            {
                sign = -1;
            }
            else if (s[i] == '(')
            {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            }
            else if(s[i] == ')')
            {
                int xsign = stk.top();
                stk.pop();
                int xresult = stk.top();
                stk.pop();
                result = result * xsign + xresult;
            }
        }
        
        return result;
    }
};
// @lc code=end

