/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result;
        // count the number of 1s in the i-th bit of all numbers
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (const int &x : nums) {
                sum += (x >> i) & 1;
            }
            result |= (sum % 3) << i;
        }
        return result;
    }
};
// @lc code=end

