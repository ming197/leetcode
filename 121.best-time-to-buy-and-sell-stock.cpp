/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        vector<int> minPrice(prices.size(), 10010);
        minPrice[0] = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            minPrice[i] = min(prices[i], minPrice[i - 1]);
            maxProfit = max(maxProfit, prices[i] - minPrice[i]);
        }
        return maxProfit;
    }
};
// @lc code=end

