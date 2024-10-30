/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for (int num : nums) {
            sum = max(sum + num, num);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
// @lc code=end

