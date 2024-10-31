/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // the max subarray of circular subarray is the maximum of
        // 1. the maximum subarray sum
        // 2. the sum of the array minus the minimum subarray sum
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int curMax = 0;
        int curMin = 0;
        // find the maximum subarray sum
        // and the minimum subarray sum using Kadane's algorithm
        for (int num : nums) {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
        }
        // if all numbers are negative, return the maximum number
        return minSum == sum ? maxSum : max(maxSum, sum - minSum);
    }
};
// @lc code=end

