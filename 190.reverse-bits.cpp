/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            // n & 1 is the last bit of n
            // result |= n & 1 is to add the last bit of n to result
            result |= n & 1;
            n >>= 1;
        }
        return result;
    }
};
// @lc code=end

