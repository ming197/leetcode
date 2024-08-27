/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (const int &x : nums) {
            result ^= x;
        }
        return result;
    }
};
// @lc code=end

