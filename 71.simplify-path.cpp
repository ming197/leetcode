/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string res;
        for(int i = 0; i < path.size(); ++i)
        {
            if(path[i] == '/') {
                // if we encounter / then continue
                continue;
            }

            string temp;
			// iterate till we doesn't traverse the whole string and doesn't encounter the last /
            while(i < path.size() && path[i] != '/')
            {
				// add path to temp string
                temp += path[i];
                ++i;
            }

            if(temp == ".") {
                continue;
            } else if(temp == "..") { // pop the top element from stack if existss
                if(!stk.empty())
                    stk.pop();
            } else {
                // push the directory file name to stack
                stk.push(temp);
            }
        }
        
		// adding all the stack elements to res
        while(!stk.empty())
        {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        
		// if no directory or file is present
        if(res.size() == 0)
            return "/";
        
        return res;
    }
};
// @lc code=end

