/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sum of [l, r)
        int prefix_sum = 0;
        int l = 0, r = 0;
        int res = nums.size() + 1;
        while (l <= r)
        {
            if (prefix_sum < target) {
                // boundary check
                if (r < nums.size()) {
                    prefix_sum += nums[r++];
                } else {
                    break;
                }
            } else if (prefix_sum >= target) {
                res = min(res, r - l);
                prefix_sum -= nums[l++];
            }
        }
        return res == nums.size() + 1 ? 0 : res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,1,1,1,1,1};
    cout << sol.minSubArrayLen(11, nums) << endl;
    return 0;
}
// @lc code=end

