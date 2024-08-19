/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        if (left == right) return nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            // two parts exist, cut the right part
            if (nums[mid] < nums[left]) {
                right = mid;
            } else if (nums[mid] > nums[left]) {
                // only one part exists
                if (nums[left] < nums[right]) {
                    return nums[left];
                } else { // two parts exist, cut the left part
                    left = mid + 1;
                }
            } else {
                // only two elements left, return the smaller one
                return nums[mid] < nums[mid + 1] ? nums[mid] : nums[mid + 1];
            }
        }
        return nums[left];
    }
};

int main() {
    vector<int> nums = {5, 1, 2, 3, 4};
    Solution().findMin(nums);
    return 0;
}


// @lc code=end

