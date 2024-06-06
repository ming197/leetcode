/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // use map to store the index of the number
        unordered_map<int, int> seen;
        // update the index of the number if the distance is more than k or the number is not in the map
        for (int i = 0; i < nums.size(); i++)
        {
            if (seen.find(nums[i]) != seen.end() && i - seen[nums[i]] <= k)
            {
                return true;
            }
            seen[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end

