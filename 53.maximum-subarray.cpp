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
    // int maxSubArray(vector<int>& nums) {
    //     int maxSum = INT_MIN;
    //     int sum = 0;
    //     for (int num : nums) {
    //         sum = max(sum + num, num);
    //         maxSum = max(maxSum, sum);
    //     }
    //     return maxSum;
    // }

    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }

    int maxSubArray(vector<int> &nums, int left, int right) {
        if (left > right) {
            return -std::pow(2, 30);
        }
        int mid = left + (right - left) / 2;
        int leftMax = maxSubArray(nums, left, mid - 1);
        int rightMax = maxSubArray(nums, mid + 1, right);
        // the maximum subarray that contains the middle element
        // and initial value of left_max and right_max is 0
        int left_max = 0;
        int right_max = 0;
        // the end of the left subarray must be mid - 1
        for (int i = mid - 1, sum = 0; i >= left; --i) {
            sum += nums[i];
            left_max = max(left_max, sum);
        }
        // the start of the right subarray must be mid + 1
        for (int i = mid + 1, sum = 0; i <= right; ++i) {
            sum += nums[i];
            right_max = max(right_max, sum);
        }
        return max({leftMax, rightMax, left_max + right_max + nums[mid]});
    }
};

int main() {
    vector<int> nums = {1};
    Solution sol;
    int res = sol.maxSubArray(nums);
    cout << res << endl;
    return 0;
}
// @lc code=end

