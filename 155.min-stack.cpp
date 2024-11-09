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
    // pair<int, int> first: val, second: min
    // the second element of the pair is the min value to the current element
    deque<pair<int, int>> min_stk_;
    MinStack() {
        
    }
    
    void push(int val) {
        if (min_stk_.empty())
        {
            min_stk_.push_front({val, val});
        }
        else
        {
            min_stk_.push_front({val, min(val, min_stk_.front().second)});
        }
    }
    
    void pop() {
        min_stk_.pop_front();
    }
    
    int top() {
        return min_stk_.front().first;
    }
    
    int getMin() {
        return min_stk_.front().second;
    }
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

