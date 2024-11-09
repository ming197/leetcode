/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> res = {-1, -1};
        if (nums.size() == 0) return res;
        // find left bound
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        res[0] = nums[left] == target ? left : -1;
        if (res[0] == -1) return res;
        right = nums.size() - 1;
        // find right bound
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2;
            if (nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        res[1] = right;
        return res;
    }
};
// @lc code=end

