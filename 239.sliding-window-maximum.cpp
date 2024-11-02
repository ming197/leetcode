/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0 || k == 0) {
            return {};
        }
        // window: the index of the element in the window
        // the nums in the window is in descending order
        deque<int> window;
        vector<int> res(nums.size() - k + 1);
        for (int i = 0; i < nums.size(); ++i) {
            // remove the element out of the window
            if (!window.empty() && window.front() == i - k) {
                window.pop_front();
            }
            // remove the element smaller than the current element
            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }
            window.push_back(i);
            if (i >= k - 1) {
                res[i - k + 1] = nums[window.front()];
            }
        }
        return res;
    }
};
// @lc code=end

