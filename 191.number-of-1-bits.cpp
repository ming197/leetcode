/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        while(n) {
            result += (n & 1);
            n >>= 1;
        }
        return result;
    }
};
// @lc code=end

