/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        deque<int> stk;
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!stk.empty() && temperatures[i] > temperatures[stk.front()])
            {
                temperatures[stk.front()] = i - stk.front();
                stk.pop_front();
            }
            stk.push_front(i);
        }
        while (!stk.empty())
        {
            temperatures[stk.front()] = 0;
            stk.pop_front();
        }
        return temperatures;
    }
};
// @lc code=end

