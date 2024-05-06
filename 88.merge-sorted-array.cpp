/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }
        if (m == 0) {
            nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
            return;
        }
        int i = m - 1, j = n - 1;
        int pos = m + n - 1;
        // operator [] is faster than the interface "at"
        while (j >= 0) {
            if (i >= 0 && nums1.at(i) > nums2.at(j)) {
                nums1.at(pos--) = nums1.at(i--);
            } else {
                nums1.at(pos--) = nums2.at(j--);
            }
        }
    }
};
// @lc code=end

