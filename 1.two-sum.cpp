/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // use a map to store the index of each number
        unordered_map<int, int> num2idx;
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            int complement = target - num;
            if (num2idx.find(complement) != num2idx.end())
            {
                return {num2idx[complement], i};
            }
            num2idx[num] = i;
        }
        return {};
    }
};
// @lc code=end

