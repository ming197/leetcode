/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class MinStack {
public:
    // pair<int,int> first element is the value and second element is the minimum value till now
    vector<pair<int,int>> stk;
	
    MinStack() { }
    
    void push(int val) {
        if(stk.empty())
            stk.push_back({val, val});
        else
            // if the current value is less than the minimum value till now 
            // then update the minimum value
            stk.push_back({val, min(stk.back().second,val)});    
    }
    
    void pop() { stk.pop_back(); }
    
    int top() { return stk.back().first; }
    
    int getMin() { return stk.back().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

