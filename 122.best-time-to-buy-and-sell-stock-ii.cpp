/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            // greedy algorithm
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};
// @lc code=end

