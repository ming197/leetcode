/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int index = -1; 
        int preSum = 0;
        int smallest = preSum;

        for (int i = 0; i < n; i++) {
            preSum += gas[i] - cost[i];
            if (preSum < smallest) {
                smallest = preSum;
                index = i;
            }
        }
        return preSum >= 0 ? index + 1 : -1;
    }
};
// @lc code=end

