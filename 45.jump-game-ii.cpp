/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // max_reachable is the farthest index that can be reached
        // last_reachable is the last index that can be reached
        int max_reachable = 0;
        int last_reachable = 0;
        int jumps = 0;
        for (int i = 0; i < n - 1; i++)
        {
            max_reachable = max(max_reachable, i + nums[i]);
            // If the current index is the last reachable index, then update the last reachable index and increment the number of jumps
            if (i == last_reachable)
            {
                last_reachable = max_reachable;
                jumps++;
            }
        }
        return jumps;
    }
};
// @lc code=end

