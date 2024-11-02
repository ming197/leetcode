/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        // sum2freq: the frequency of the sum of the subarray 
        // from the beginning to one specific index
        unordered_map<int, int> sum2freq;
        sum2freq[0] = 1;
        int sum = 0;
        // if to find the subarray sum equals k
        // the sum before the subarray sum should be sum - k
        for (int num : nums) {
            sum += num;
            res += sum2freq[sum - k];
            sum2freq[sum]++;
        }
        return res;
    }
};
// @lc code=end

