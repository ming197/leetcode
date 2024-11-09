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
        int l = 0, r = nums.size() - 1;
        // if it is sorted, return the first element
        if (nums[l] < nums[r])
        {
            return nums[l];
        }
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            // if mid is greater than right, then the minimum is in the right part
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            } else {
                if (nums[mid] < nums[r])
                {
                    r = mid;
                } else {
                    return nums[mid];
                }
            }
        }
        return nums[l];
    }
};



// @lc code=end

