/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] > nums[r])
            {
                if (target > nums[mid])
                {
                    l = mid + 1;
                }
                else
                {
                    if (target >= nums[l])
                    {
                        r = mid;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }
            else // nums[mid] < nums[r]
            {
                if (target > nums[mid])
                {
                    if (target <= nums[r])
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid;
                    }
                }
                else
                {
                    r = mid;
                }
            }
        }
        return nums[l] == target ? l : -1;
    }
};


// @lc code=end

