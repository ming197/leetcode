/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            // the maximum number of delta should be less than mask
            // or there must be a carry in the i-th bit, it will be 0
            if ((right - left) < mask && (left & mask) && (right & mask)) {
                result |= mask;
            }
        }
        return result;
    }
};
// @lc code=end

