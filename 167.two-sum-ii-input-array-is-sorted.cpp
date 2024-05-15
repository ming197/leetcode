/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r)
        {
            if (numbers[l] + numbers[r] == target) {
                return vector<int>{l + 1, r + 1};
            } else if (numbers[l] + numbers[r] > target) {
                --r;
            } else {
                ++l;
            }
        }
        return vector<int>{0, 0};
    }
};
// @lc code=end

